// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: coms.proto

#include "coms.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_coms_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_std_coms_2eproto;
namespace reverse {
class stdDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<std> _instance;
} _std_default_instance_;
class reverseRequestDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<reverseRequest> _instance;
} _reverseRequest_default_instance_;
class reverseResponseDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<reverseResponse> _instance;
} _reverseResponse_default_instance_;
}  // namespace reverse
static void InitDefaultsscc_info_reverseRequest_coms_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::reverse::_reverseRequest_default_instance_;
    new (ptr) ::reverse::reverseRequest();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::reverse::reverseRequest::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_reverseRequest_coms_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_reverseRequest_coms_2eproto}, {
      &scc_info_std_coms_2eproto.base,}};

static void InitDefaultsscc_info_reverseResponse_coms_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::reverse::_reverseResponse_default_instance_;
    new (ptr) ::reverse::reverseResponse();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::reverse::reverseResponse::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_reverseResponse_coms_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 1, 0, InitDefaultsscc_info_reverseResponse_coms_2eproto}, {
      &scc_info_std_coms_2eproto.base,}};

static void InitDefaultsscc_info_std_coms_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::reverse::_std_default_instance_;
    new (ptr) ::reverse::std();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::reverse::std::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_std_coms_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, 0, InitDefaultsscc_info_std_coms_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_coms_2eproto[3];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_coms_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_coms_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_coms_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::reverse::std, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::reverse::std, in_),
  PROTOBUF_FIELD_OFFSET(::reverse::std, out_),
  PROTOBUF_FIELD_OFFSET(::reverse::std, err_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::reverse::reverseRequest, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::reverse::reverseRequest, std_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::reverse::reverseResponse, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::reverse::reverseResponse, std_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::reverse::std)},
  { 8, -1, sizeof(::reverse::reverseRequest)},
  { 14, -1, sizeof(::reverse::reverseResponse)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::reverse::_std_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::reverse::_reverseRequest_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::reverse::_reverseResponse_default_instance_),
};

const char descriptor_table_protodef_coms_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ncoms.proto\022\007reverse\"+\n\003std\022\n\n\002in\030\001 \001(\t"
  "\022\013\n\003out\030\002 \001(\t\022\013\n\003err\030\003 \001(\t\"+\n\016reverseReq"
  "uest\022\031\n\003std\030\001 \001(\0132\014.reverse.std\",\n\017rever"
  "seResponse\022\031\n\003std\030\001 \001(\0132\014.reverse.std2J\n"
  "\nReverseTCP\022<\n\007Execute\022\027.reverse.reverse"
  "Request\032\030.reverse.reverseResponseB\rZ\013./r"
  "eversepbb\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_coms_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_coms_2eproto_sccs[3] = {
  &scc_info_reverseRequest_coms_2eproto.base,
  &scc_info_reverseResponse_coms_2eproto.base,
  &scc_info_std_coms_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_coms_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_coms_2eproto = {
  false, false, descriptor_table_protodef_coms_2eproto, "coms.proto", 256,
  &descriptor_table_coms_2eproto_once, descriptor_table_coms_2eproto_sccs, descriptor_table_coms_2eproto_deps, 3, 0,
  schemas, file_default_instances, TableStruct_coms_2eproto::offsets,
  file_level_metadata_coms_2eproto, 3, file_level_enum_descriptors_coms_2eproto, file_level_service_descriptors_coms_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_coms_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_coms_2eproto)), true);
namespace reverse {

// ===================================================================

void std::InitAsDefaultInstance() {
}
class std::_Internal {
 public:
};

std::std(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:reverse.std)
}
std::std(const std& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  in_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_in().empty()) {
    in_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_in(),
      GetArena());
  }
  out_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_out().empty()) {
    out_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_out(),
      GetArena());
  }
  err_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (!from._internal_err().empty()) {
    err_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from._internal_err(),
      GetArena());
  }
  // @@protoc_insertion_point(copy_constructor:reverse.std)
}

void std::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_std_coms_2eproto.base);
  in_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  out_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  err_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

std::~std() {
  // @@protoc_insertion_point(destructor:reverse.std)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void std::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  in_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  out_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  err_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void std::ArenaDtor(void* object) {
  std* _this = reinterpret_cast< std* >(object);
  (void)_this;
}
void std::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void std::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const std& std::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_std_coms_2eproto.base);
  return *internal_default_instance();
}


void std::Clear() {
// @@protoc_insertion_point(message_clear_start:reverse.std)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  in_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  out_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  err_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* std::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string in = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          auto str = _internal_mutable_in();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "reverse.std.in"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string out = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          auto str = _internal_mutable_out();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "reverse.std.out"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // string err = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          auto str = _internal_mutable_err();
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "reverse.std.err"));
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* std::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:reverse.std)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string in = 1;
  if (this->in().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_in().data(), static_cast<int>(this->_internal_in().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "reverse.std.in");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_in(), target);
  }

  // string out = 2;
  if (this->out().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_out().data(), static_cast<int>(this->_internal_out().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "reverse.std.out");
    target = stream->WriteStringMaybeAliased(
        2, this->_internal_out(), target);
  }

  // string err = 3;
  if (this->err().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_err().data(), static_cast<int>(this->_internal_err().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "reverse.std.err");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_err(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:reverse.std)
  return target;
}

size_t std::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:reverse.std)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string in = 1;
  if (this->in().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_in());
  }

  // string out = 2;
  if (this->out().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_out());
  }

  // string err = 3;
  if (this->err().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_err());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void std::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:reverse.std)
  GOOGLE_DCHECK_NE(&from, this);
  const std* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<std>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:reverse.std)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:reverse.std)
    MergeFrom(*source);
  }
}

void std::MergeFrom(const std& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:reverse.std)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.in().size() > 0) {
    _internal_set_in(from._internal_in());
  }
  if (from.out().size() > 0) {
    _internal_set_out(from._internal_out());
  }
  if (from.err().size() > 0) {
    _internal_set_err(from._internal_err());
  }
}

void std::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:reverse.std)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void std::CopyFrom(const std& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:reverse.std)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool std::IsInitialized() const {
  return true;
}

void std::InternalSwap(std* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  in_.Swap(&other->in_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  out_.Swap(&other->out_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
  err_.Swap(&other->err_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}

::PROTOBUF_NAMESPACE_ID::Metadata std::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void reverseRequest::InitAsDefaultInstance() {
  ::reverse::_reverseRequest_default_instance_._instance.get_mutable()->std_ = const_cast< ::reverse::std*>(
      ::reverse::std::internal_default_instance());
}
class reverseRequest::_Internal {
 public:
  static const ::reverse::std& std(const reverseRequest* msg);
};

const ::reverse::std&
reverseRequest::_Internal::std(const reverseRequest* msg) {
  return *msg->std_;
}
reverseRequest::reverseRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:reverse.reverseRequest)
}
reverseRequest::reverseRequest(const reverseRequest& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_std()) {
    std_ = new ::reverse::std(*from.std_);
  } else {
    std_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:reverse.reverseRequest)
}

void reverseRequest::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_reverseRequest_coms_2eproto.base);
  std_ = nullptr;
}

reverseRequest::~reverseRequest() {
  // @@protoc_insertion_point(destructor:reverse.reverseRequest)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void reverseRequest::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete std_;
}

void reverseRequest::ArenaDtor(void* object) {
  reverseRequest* _this = reinterpret_cast< reverseRequest* >(object);
  (void)_this;
}
void reverseRequest::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void reverseRequest::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const reverseRequest& reverseRequest::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_reverseRequest_coms_2eproto.base);
  return *internal_default_instance();
}


void reverseRequest::Clear() {
// @@protoc_insertion_point(message_clear_start:reverse.reverseRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && std_ != nullptr) {
    delete std_;
  }
  std_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* reverseRequest::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .reverse.std std = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_std(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* reverseRequest::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:reverse.reverseRequest)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .reverse.std std = 1;
  if (this->has_std()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::std(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:reverse.reverseRequest)
  return target;
}

size_t reverseRequest::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:reverse.reverseRequest)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .reverse.std std = 1;
  if (this->has_std()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *std_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void reverseRequest::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:reverse.reverseRequest)
  GOOGLE_DCHECK_NE(&from, this);
  const reverseRequest* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<reverseRequest>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:reverse.reverseRequest)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:reverse.reverseRequest)
    MergeFrom(*source);
  }
}

void reverseRequest::MergeFrom(const reverseRequest& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:reverse.reverseRequest)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_std()) {
    _internal_mutable_std()->::reverse::std::MergeFrom(from._internal_std());
  }
}

void reverseRequest::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:reverse.reverseRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void reverseRequest::CopyFrom(const reverseRequest& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:reverse.reverseRequest)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool reverseRequest::IsInitialized() const {
  return true;
}

void reverseRequest::InternalSwap(reverseRequest* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(std_, other->std_);
}

::PROTOBUF_NAMESPACE_ID::Metadata reverseRequest::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void reverseResponse::InitAsDefaultInstance() {
  ::reverse::_reverseResponse_default_instance_._instance.get_mutable()->std_ = const_cast< ::reverse::std*>(
      ::reverse::std::internal_default_instance());
}
class reverseResponse::_Internal {
 public:
  static const ::reverse::std& std(const reverseResponse* msg);
};

const ::reverse::std&
reverseResponse::_Internal::std(const reverseResponse* msg) {
  return *msg->std_;
}
reverseResponse::reverseResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:reverse.reverseResponse)
}
reverseResponse::reverseResponse(const reverseResponse& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_std()) {
    std_ = new ::reverse::std(*from.std_);
  } else {
    std_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:reverse.reverseResponse)
}

void reverseResponse::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_reverseResponse_coms_2eproto.base);
  std_ = nullptr;
}

reverseResponse::~reverseResponse() {
  // @@protoc_insertion_point(destructor:reverse.reverseResponse)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void reverseResponse::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete std_;
}

void reverseResponse::ArenaDtor(void* object) {
  reverseResponse* _this = reinterpret_cast< reverseResponse* >(object);
  (void)_this;
}
void reverseResponse::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void reverseResponse::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const reverseResponse& reverseResponse::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_reverseResponse_coms_2eproto.base);
  return *internal_default_instance();
}


void reverseResponse::Clear() {
// @@protoc_insertion_point(message_clear_start:reverse.reverseResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArena() == nullptr && std_ != nullptr) {
    delete std_;
  }
  std_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* reverseResponse::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .reverse.std std = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_std(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* reverseResponse::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:reverse.reverseResponse)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .reverse.std std = 1;
  if (this->has_std()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::std(this), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:reverse.reverseResponse)
  return target;
}

size_t reverseResponse::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:reverse.reverseResponse)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .reverse.std std = 1;
  if (this->has_std()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *std_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void reverseResponse::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:reverse.reverseResponse)
  GOOGLE_DCHECK_NE(&from, this);
  const reverseResponse* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<reverseResponse>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:reverse.reverseResponse)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:reverse.reverseResponse)
    MergeFrom(*source);
  }
}

void reverseResponse::MergeFrom(const reverseResponse& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:reverse.reverseResponse)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_std()) {
    _internal_mutable_std()->::reverse::std::MergeFrom(from._internal_std());
  }
}

void reverseResponse::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:reverse.reverseResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void reverseResponse::CopyFrom(const reverseResponse& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:reverse.reverseResponse)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool reverseResponse::IsInitialized() const {
  return true;
}

void reverseResponse::InternalSwap(reverseResponse* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  swap(std_, other->std_);
}

::PROTOBUF_NAMESPACE_ID::Metadata reverseResponse::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace reverse
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::reverse::std* Arena::CreateMaybeMessage< ::reverse::std >(Arena* arena) {
  return Arena::CreateMessageInternal< ::reverse::std >(arena);
}
template<> PROTOBUF_NOINLINE ::reverse::reverseRequest* Arena::CreateMaybeMessage< ::reverse::reverseRequest >(Arena* arena) {
  return Arena::CreateMessageInternal< ::reverse::reverseRequest >(arena);
}
template<> PROTOBUF_NOINLINE ::reverse::reverseResponse* Arena::CreateMaybeMessage< ::reverse::reverseResponse >(Arena* arena) {
  return Arena::CreateMessageInternal< ::reverse::reverseResponse >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
