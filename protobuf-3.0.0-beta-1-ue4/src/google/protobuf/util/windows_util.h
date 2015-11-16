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

#ifndef GOOGLE_PROTOBUF_UTIL_WINDOWS_UTIL_H__
#define GOOGLE_PROTOBUF_UTIL_WINDOWS_UTIL_H__

#include <string>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/util/json_util.h>


namespace google {
	namespace protobuf {
		class Closure;
		class Descriptor;
		class Message;
		class RpcController;
		namespace util {
			class TypeResolver;
		}  // namespace util.
	}  // namespace protobuf.
}  // namespace google.


namespace google {
	namespace protobuf {
		namespace util {
			// Static functions in this namespace are used to provide safe-ish wrappers for use by Windows deployments
			// where libprotobuf is compiled as a DLL. In windows, each DLL has it's own heap so it's critical that
			// objects are destroyed in the DLL which created them.
			namespace windows {
				// Serializes a proto
				LIBPROTOBUF_EXPORT util::Status SerializeToJsonString(
					TypeResolver* resolver, const string& type_url, const string& binary_input,
					string** json_output, const JsonOptions& options);

				// A wrapper which serializes a protobuf into a text string.
				LIBPROTOBUF_EXPORT bool SerializeToTextString(
					const google::protobuf::Message& message, string** text_output);

				LIBPROTOBUF_EXPORT void SerializeToBinaryString(
					const google::protobuf::Message& message, string** binary_output);

				// A wrapper which creates a protobuf from a json string.
				LIBPROTOBUF_EXPORT bool ParseFromJsonString(
					const google::protobuf::Descriptor* descriptor, google::protobuf::util::TypeResolver* resolver,
					const string& type_url, const string& json_input, google::protobuf::Message** message_output);

				// A wrapper which creates a protobuf from a text string.
				LIBPROTOBUF_EXPORT bool ParseFromTextString(
					const google::protobuf::Descriptor* descriptor, const string& text_input, 
					google::protobuf::Message** message_output);

				// A wrapper which creates a protobuf from a binary string.
				LIBPROTOBUF_EXPORT bool ParseFromBinary(
					const google::protobuf::Descriptor* descriptor, const string& binary_input, 
					google::protobuf::Message** message_output);

				// Frees a string which was previously created by the protobuf library. This enables
				// safe-ish consumption of strings allocated on the protobuf heap (if built as a DLL).
				LIBPROTOBUF_EXPORT void DeleteString(string* string_ptr);

				// Frees a message which was previously created by the protobuf library. This enables
				// safe-ish consumption of messages allocated on the protobuf heap (if built as a DLL).
				LIBPROTOBUF_EXPORT void DeleteMessage(google::protobuf::Message* message_ptr);
			}
		}  // namespace util
	}  // namespace protobuf
}  // namespace google.
#endif  // GOOGLE_PROTOBUF_UTIL_WINDOWS_H_