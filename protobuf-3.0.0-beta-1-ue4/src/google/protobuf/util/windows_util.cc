// Protocol Buffers - Google's data interchange format
// Copyright 2008 Google Inc.  All rights reserved.
// https://developers.google.com/protocol-buffers/
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// Author: san.mehat@gmail.com (San Mehat)

#include <google/protobuf/descriptor.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/message.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/util/json_util.h>
#include <google/protobuf/util/type_resolver_util.h>

#include <google/protobuf/util/windows_util.h>

using google::protobuf::DynamicMessageFactory;
using google::protobuf::Message;
using google::protobuf::util::JsonOptions;
using google::protobuf::util::Status;
using google::protobuf::util::TypeResolver;

namespace google {
namespace protobuf {
namespace util {
namespace windows {
static DynamicMessageFactory Sdynamic_message_factory;

Status SerializeToJsonString(TypeResolver* resolver, const string& type_url, const string& binary_input,
						  string** json_output, const JsonOptions& options) {
	*json_output = new string();
	Status status = google::protobuf::util::BinaryToJsonString(resolver, type_url, binary_input, *json_output, options);
	if (!status.ok()) {
		delete *json_output;
		*json_output = NULL;
	}
	return status;
}

bool SerializeToTextString(const Message& message, string** text_output) {
	*text_output= new string();
	if (!google::protobuf::TextFormat::PrintToString(message, *text_output)) {
		delete *text_output;
		*text_output = nullptr;
		return false;
	}
	return true;
}


void SerializeToBinaryString(const Message& message, string** binary_output) {
	*binary_output = new string(message.SerializeAsString());
}

bool ParseFromJsonString(const Descriptor* descriptor,
						 TypeResolver* resolver, 
						 const string& type_url, 
						 string& json_input, 
						 Message** message_output) {
	string binary_data;
	Status status = google::protobuf::util::JsonToBinaryString(resolver, type_url, json_input, &binary_data);
	if (!status.ok()) {
		return false;
	}
	return google::protobuf::util::windows::ParseFromBinary(descriptor, binary_data, message_output);
}

bool ParseFromTextString(const Descriptor* descriptor, const string&text_string, Message** message_output) {
	DynamicMessageFactory dmf;
	*message_output = dmf.GetPrototype(descriptor)->New();
	if (!google::protobuf::TextFormat::ParseFromString(text_string, *message_output)) {
		delete *message_output;
		*message_output = nullptr;
		return false;
	}
	return true;
}

bool ParseFromBinary(const Descriptor* descriptor, const string& binary_input, Message** message_output) {
	DynamicMessageFactory dmf;
	*message_output = dmf.GetPrototype(descriptor)->New();
	if (!(*message_output)->ParseFromString(binary_input)) {
		delete *message_output;
		return false;
	}
	return true;
}

void DeleteString(string* string_ptr) {
	delete string_ptr;
}

void DeleteMessage(Message* message_ptr) {
	delete message_ptr;
}

}  // namespace windows
}  // namespace util
}  // namespace protobuf
}  // namespace google
