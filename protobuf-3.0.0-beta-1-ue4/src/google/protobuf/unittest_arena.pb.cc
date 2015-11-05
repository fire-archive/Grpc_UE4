// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/unittest_arena.proto

#if WITH_GOOGLE_PROTOBUF_BINDING == 1
#include "AllowWindowsPlatformTypes.h"
#endif // WITH_GOOGLE_PROTOBUF_BINDING

#if _MSC_VER >= 1300
#ifndef _PS3
#pragma warning(push)
#pragma warning(disable : 4530)	// warning C4530: C++ exception handler used, but unwind semantics are not enabled. Specify /EHsc (disabled due to std headers having exception syntax)
#pragma warning(disable : 4512)	// warning C4512: assignment operator could not be generated
#pragma warning(disable : 4244)	// warning C4244:  warning C4244: '=' : conversion from '__w64 int' to 'int', possible loss of data
#pragma warning(disable : 4267)	// warning C4267: 'argument' : conversion from 'size_t' to 'int', possible loss of data
#pragma warning(disable : 4125)	// warning C4125: decimal digit terminates octal escape sequence
#pragma warning(disable : 4127)	// warning C4127: conditional expression is constant
#pragma warning(disable : 4100)	// warning C4100: 'op' : unreferenced formal parameter
#endif // _PS3
#endif // _MSC_VER
#if _GNUC
#ifndef _PS3
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#endif // _PS3
#endif // _GNUC

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "google/protobuf/unittest_arena.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace proto2_arena_unittest {

namespace {

const ::google::protobuf::Descriptor* NestedMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  NestedMessage_reflection_ = NULL;
const ::google::protobuf::Descriptor* ArenaMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArenaMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_google_2fprotobuf_2funittest_5farena_2eproto() {
  protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "google/protobuf/unittest_arena.proto");
  GOOGLE_CHECK(file != NULL);
  NestedMessage_descriptor_ = file->message_type(0);
  static const int NestedMessage_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NestedMessage, d_),
  };
  NestedMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      NestedMessage_descriptor_,
      NestedMessage::default_instance_,
      NestedMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NestedMessage, _has_bits_[0]),
      -1,
      -1,
      sizeof(NestedMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(NestedMessage, _internal_metadata_),
      -1);
  ArenaMessage_descriptor_ = file->message_type(1);
  static const int ArenaMessage_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, repeated_nested_message_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, repeated_import_no_arena_message_),
  };
  ArenaMessage_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ArenaMessage_descriptor_,
      ArenaMessage::default_instance_,
      ArenaMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, _has_bits_[0]),
      -1,
      -1,
      sizeof(ArenaMessage),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaMessage, _internal_metadata_),
      -1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_google_2fprotobuf_2funittest_5farena_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      NestedMessage_descriptor_, &NestedMessage::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ArenaMessage_descriptor_, &ArenaMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_google_2fprotobuf_2funittest_5farena_2eproto() {
  delete NestedMessage::default_instance_;
  delete NestedMessage_reflection_;
  delete ArenaMessage::default_instance_;
  delete ArenaMessage_reflection_;
}

void protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::proto2_arena_unittest::protobuf_AddDesc_google_2fprotobuf_2funittest_5fno_5farena_5fimport_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n$google/protobuf/unittest_arena.proto\022\025"
    "proto2_arena_unittest\032.google/protobuf/u"
    "nittest_no_arena_import.proto\"\032\n\rNestedM"
    "essage\022\t\n\001d\030\001 \001(\005\"\262\001\n\014ArenaMessage\022E\n\027re"
    "peated_nested_message\030\001 \003(\0132$.proto2_are"
    "na_unittest.NestedMessage\022[\n repeated_im"
    "port_no_arena_message\030\002 \003(\01321.proto2_are"
    "na_unittest.ImportNoArenaNestedMessageB\003"
    "\370\001\001", 323);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "google/protobuf/unittest_arena.proto", &protobuf_RegisterTypes);
  NestedMessage::default_instance_ = new NestedMessage();
  ArenaMessage::default_instance_ = new ArenaMessage();
  NestedMessage::default_instance_->InitAsDefaultInstance();
  ArenaMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_google_2fprotobuf_2funittest_5farena_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_google_2fprotobuf_2funittest_5farena_2eproto {
  StaticDescriptorInitializer_google_2fprotobuf_2funittest_5farena_2eproto() {
    protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto();
  }
} static_descriptor_initializer_google_2fprotobuf_2funittest_5farena_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD;
static void MergeFromFail(int line) {
  GOOGLE_CHECK(false) << __FILE__ << ":" << line;
}

}  // namespace


// ===================================================================

#ifndef _MSC_VER
const int NestedMessage::kDFieldNumber;
#endif  // !_MSC_VER

NestedMessage::NestedMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto2_arena_unittest.NestedMessage)
}

NestedMessage::NestedMessage(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto2_arena_unittest.NestedMessage)
}

void NestedMessage::InitAsDefaultInstance() {
}

NestedMessage::NestedMessage(const NestedMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto2_arena_unittest.NestedMessage)
}

void NestedMessage::SharedCtor() {
  _cached_size_ = 0;
  d_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

NestedMessage::~NestedMessage() {
  // @@protoc_insertion_point(destructor:proto2_arena_unittest.NestedMessage)
  SharedDtor();
}

void NestedMessage::SharedDtor() {
  if (GetArenaNoVirtual() != NULL) {
    return;
  }

  if (this != default_instance_) {
  }
}

void NestedMessage::ArenaDtor(void* object) {
  NestedMessage* _this = reinterpret_cast< NestedMessage* >(object);
  (void)_this;
}
void NestedMessage::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void NestedMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* NestedMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return NestedMessage_descriptor_;
}

const NestedMessage& NestedMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto();
  return *default_instance_;
}

NestedMessage* NestedMessage::default_instance_ = NULL;

NestedMessage* NestedMessage::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<NestedMessage>(arena);
}

void NestedMessage::Clear() {
  d_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool NestedMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto2_arena_unittest.NestedMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 d = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &d_)));
          set_has_d();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto2_arena_unittest.NestedMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto2_arena_unittest.NestedMessage)
  return false;
#undef DO_
}

void NestedMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto2_arena_unittest.NestedMessage)
  // optional int32 d = 1;
  if (has_d()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->d(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto2_arena_unittest.NestedMessage)
}

::google::protobuf::uint8* NestedMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto2_arena_unittest.NestedMessage)
  // optional int32 d = 1;
  if (has_d()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->d(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto2_arena_unittest.NestedMessage)
  return target;
}

int NestedMessage::ByteSize() const {
  int total_size = 0;

  // optional int32 d = 1;
  if (has_d()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->d());
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void NestedMessage::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const NestedMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const NestedMessage>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void NestedMessage::MergeFrom(const NestedMessage& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_d()) {
      set_d(from.d());
    }
  }
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void NestedMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void NestedMessage::CopyFrom(const NestedMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool NestedMessage::IsInitialized() const {

  return true;
}

void NestedMessage::Swap(NestedMessage* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    NestedMessage temp;
    temp.MergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void NestedMessage::UnsafeArenaSwap(NestedMessage* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void NestedMessage::InternalSwap(NestedMessage* other) {
  std::swap(d_, other->d_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata NestedMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = NestedMessage_descriptor_;
  metadata.reflection = NestedMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// NestedMessage

// optional int32 d = 1;
bool NestedMessage::has_d() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
void NestedMessage::set_has_d() {
  _has_bits_[0] |= 0x00000001u;
}
void NestedMessage::clear_has_d() {
  _has_bits_[0] &= ~0x00000001u;
}
void NestedMessage::clear_d() {
  d_ = 0;
  clear_has_d();
}
 ::google::protobuf::int32 NestedMessage::d() const {
  // @@protoc_insertion_point(field_get:proto2_arena_unittest.NestedMessage.d)
  return d_;
}
 void NestedMessage::set_d(::google::protobuf::int32 value) {
  set_has_d();
  d_ = value;
  // @@protoc_insertion_point(field_set:proto2_arena_unittest.NestedMessage.d)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

#ifndef _MSC_VER
const int ArenaMessage::kRepeatedNestedMessageFieldNumber;
const int ArenaMessage::kRepeatedImportNoArenaMessageFieldNumber;
#endif  // !_MSC_VER

ArenaMessage::ArenaMessage()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:proto2_arena_unittest.ArenaMessage)
}

ArenaMessage::ArenaMessage(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena),
  repeated_nested_message_(arena),
  repeated_import_no_arena_message_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:proto2_arena_unittest.ArenaMessage)
}

void ArenaMessage::InitAsDefaultInstance() {
}

ArenaMessage::ArenaMessage(const ArenaMessage& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:proto2_arena_unittest.ArenaMessage)
}

void ArenaMessage::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArenaMessage::~ArenaMessage() {
  // @@protoc_insertion_point(destructor:proto2_arena_unittest.ArenaMessage)
  SharedDtor();
}

void ArenaMessage::SharedDtor() {
  if (GetArenaNoVirtual() != NULL) {
    return;
  }

  if (this != default_instance_) {
  }
}

void ArenaMessage::ArenaDtor(void* object) {
  ArenaMessage* _this = reinterpret_cast< ArenaMessage* >(object);
  (void)_this;
}
void ArenaMessage::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void ArenaMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArenaMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArenaMessage_descriptor_;
}

const ArenaMessage& ArenaMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_google_2fprotobuf_2funittest_5farena_2eproto();
  return *default_instance_;
}

ArenaMessage* ArenaMessage::default_instance_ = NULL;

ArenaMessage* ArenaMessage::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<ArenaMessage>(arena);
}

void ArenaMessage::Clear() {
  repeated_nested_message_.Clear();
  repeated_import_no_arena_message_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  if (_internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->Clear();
  }
}

bool ArenaMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:proto2_arena_unittest.ArenaMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
      case 1: {
        if (tag == 10) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_repeated_nested_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_repeated_nested_message()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_loop_repeated_nested_message;
        if (input->ExpectTag(18)) goto parse_loop_repeated_import_no_arena_message;
        input->UnsafeDecrementRecursionDepth();
        break;
      }

      // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
      case 2: {
        if (tag == 18) {
          DO_(input->IncrementRecursionDepth());
         parse_loop_repeated_import_no_arena_message:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtualNoRecursionDepth(
                input, add_repeated_import_no_arena_message()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_loop_repeated_import_no_arena_message;
        input->UnsafeDecrementRecursionDepth();
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:proto2_arena_unittest.ArenaMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:proto2_arena_unittest.ArenaMessage)
  return false;
#undef DO_
}

void ArenaMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:proto2_arena_unittest.ArenaMessage)
  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  for (unsigned int i = 0, n = this->repeated_nested_message_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->repeated_nested_message(i), output);
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  for (unsigned int i = 0, n = this->repeated_import_no_arena_message_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->repeated_import_no_arena_message(i), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:proto2_arena_unittest.ArenaMessage)
}

::google::protobuf::uint8* ArenaMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:proto2_arena_unittest.ArenaMessage)
  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  for (unsigned int i = 0, n = this->repeated_nested_message_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->repeated_nested_message(i), target);
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  for (unsigned int i = 0, n = this->repeated_import_no_arena_message_size(); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->repeated_import_no_arena_message(i), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:proto2_arena_unittest.ArenaMessage)
  return target;
}

int ArenaMessage::ByteSize() const {
  int total_size = 0;

  // repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
  total_size += 1 * this->repeated_nested_message_size();
  for (int i = 0; i < this->repeated_nested_message_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->repeated_nested_message(i));
  }

  // repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
  total_size += 1 * this->repeated_import_no_arena_message_size();
  for (int i = 0; i < this->repeated_import_no_arena_message_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->repeated_import_no_arena_message(i));
  }

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArenaMessage::MergeFrom(const ::google::protobuf::Message& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ArenaMessage* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const ArenaMessage>(
          &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArenaMessage::MergeFrom(const ArenaMessage& from) {
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  repeated_nested_message_.MergeFrom(from.repeated_nested_message_);
  repeated_import_no_arena_message_.MergeFrom(from.repeated_import_no_arena_message_);
  if (from._internal_metadata_.have_unknown_fields()) {
    mutable_unknown_fields()->MergeFrom(from.unknown_fields());
  }
}

void ArenaMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArenaMessage::CopyFrom(const ArenaMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArenaMessage::IsInitialized() const {

  return true;
}

void ArenaMessage::Swap(ArenaMessage* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    ArenaMessage temp;
    temp.MergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void ArenaMessage::UnsafeArenaSwap(ArenaMessage* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void ArenaMessage::InternalSwap(ArenaMessage* other) {
  repeated_nested_message_.UnsafeArenaSwap(&other->repeated_nested_message_);
  repeated_import_no_arena_message_.UnsafeArenaSwap(&other->repeated_import_no_arena_message_);
  std::swap(_has_bits_[0], other->_has_bits_[0]);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ArenaMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArenaMessage_descriptor_;
  metadata.reflection = ArenaMessage_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ArenaMessage

// repeated .proto2_arena_unittest.NestedMessage repeated_nested_message = 1;
int ArenaMessage::repeated_nested_message_size() const {
  return repeated_nested_message_.size();
}
void ArenaMessage::clear_repeated_nested_message() {
  repeated_nested_message_.Clear();
}
const ::proto2_arena_unittest::NestedMessage& ArenaMessage::repeated_nested_message(int index) const {
  // @@protoc_insertion_point(field_get:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_.Get(index);
}
::proto2_arena_unittest::NestedMessage* ArenaMessage::mutable_repeated_nested_message(int index) {
  // @@protoc_insertion_point(field_mutable:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_.Mutable(index);
}
::proto2_arena_unittest::NestedMessage* ArenaMessage::add_repeated_nested_message() {
  // @@protoc_insertion_point(field_add:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_.Add();
}
::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::NestedMessage >*
ArenaMessage::mutable_repeated_nested_message() {
  // @@protoc_insertion_point(field_mutable_list:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return &repeated_nested_message_;
}
const ::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::NestedMessage >&
ArenaMessage::repeated_nested_message() const {
  // @@protoc_insertion_point(field_list:proto2_arena_unittest.ArenaMessage.repeated_nested_message)
  return repeated_nested_message_;
}

// repeated .proto2_arena_unittest.ImportNoArenaNestedMessage repeated_import_no_arena_message = 2;
int ArenaMessage::repeated_import_no_arena_message_size() const {
  return repeated_import_no_arena_message_.size();
}
void ArenaMessage::clear_repeated_import_no_arena_message() {
  repeated_import_no_arena_message_.Clear();
}
const ::proto2_arena_unittest::ImportNoArenaNestedMessage& ArenaMessage::repeated_import_no_arena_message(int index) const {
  // @@protoc_insertion_point(field_get:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_.Get(index);
}
::proto2_arena_unittest::ImportNoArenaNestedMessage* ArenaMessage::mutable_repeated_import_no_arena_message(int index) {
  // @@protoc_insertion_point(field_mutable:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_.Mutable(index);
}
::proto2_arena_unittest::ImportNoArenaNestedMessage* ArenaMessage::add_repeated_import_no_arena_message() {
  // @@protoc_insertion_point(field_add:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_.Add();
}
::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::ImportNoArenaNestedMessage >*
ArenaMessage::mutable_repeated_import_no_arena_message() {
  // @@protoc_insertion_point(field_mutable_list:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return &repeated_import_no_arena_message_;
}
const ::google::protobuf::RepeatedPtrField< ::proto2_arena_unittest::ImportNoArenaNestedMessage >&
ArenaMessage::repeated_import_no_arena_message() const {
  // @@protoc_insertion_point(field_list:proto2_arena_unittest.ArenaMessage.repeated_import_no_arena_message)
  return repeated_import_no_arena_message_;
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto2_arena_unittest

// @@protoc_insertion_point(global_scope)

#if _MSC_VER >= 1300
#ifndef _PS3
#pragma warning( pop )
#endif // _PS3
#endif // _MSC_VER
#if _GNUC
#ifndef _PS3
#pragma GCC diagnostic pop
#endif // _PS3
#endif // _GNUC

