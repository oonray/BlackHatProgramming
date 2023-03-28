// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: coms.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_coms_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_coms_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_coms_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_coms_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_coms_2eproto;
namespace reverse {
class reverseRequest;
class reverseRequestDefaultTypeInternal;
extern reverseRequestDefaultTypeInternal _reverseRequest_default_instance_;
class reverseResponse;
class reverseResponseDefaultTypeInternal;
extern reverseResponseDefaultTypeInternal _reverseResponse_default_instance_;
class std;
class stdDefaultTypeInternal;
extern stdDefaultTypeInternal _std_default_instance_;
}  // namespace reverse
PROTOBUF_NAMESPACE_OPEN
template<> ::reverse::reverseRequest* Arena::CreateMaybeMessage<::reverse::reverseRequest>(Arena*);
template<> ::reverse::reverseResponse* Arena::CreateMaybeMessage<::reverse::reverseResponse>(Arena*);
template<> ::reverse::std* Arena::CreateMaybeMessage<::reverse::std>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace reverse {

// ===================================================================

class std PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:reverse.std) */ {
 public:
  inline std() : std(nullptr) {};
  virtual ~std();

  std(const std& from);
  std(std&& from) noexcept
    : std() {
    *this = ::std::move(from);
  }

  inline std& operator=(const std& from) {
    CopyFrom(from);
    return *this;
  }
  inline std& operator=(std&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const std& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const std* internal_default_instance() {
    return reinterpret_cast<const std*>(
               &_std_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(std& a, std& b) {
    a.Swap(&b);
  }
  inline void Swap(std* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(std* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline std* New() const final {
    return CreateMaybeMessage<std>(nullptr);
  }

  std* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<std>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const std& from);
  void MergeFrom(const std& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(std* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "reverse.std";
  }
  protected:
  explicit std(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_coms_2eproto);
    return ::descriptor_table_coms_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kInFieldNumber = 1,
    kOutFieldNumber = 2,
    kErrFieldNumber = 3,
  };
  // string in = 1;
  void clear_in();
  const std::string& in() const;
  void set_in(const std::string& value);
  void set_in(std::string&& value);
  void set_in(const char* value);
  void set_in(const char* value, size_t size);
  std::string* mutable_in();
  std::string* release_in();
  void set_allocated_in(std::string* in);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_in();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_in(
      std::string* in);
  private:
  const std::string& _internal_in() const;
  void _internal_set_in(const std::string& value);
  std::string* _internal_mutable_in();
  public:

  // string out = 2;
  void clear_out();
  const std::string& out() const;
  void set_out(const std::string& value);
  void set_out(std::string&& value);
  void set_out(const char* value);
  void set_out(const char* value, size_t size);
  std::string* mutable_out();
  std::string* release_out();
  void set_allocated_out(std::string* out);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_out();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_out(
      std::string* out);
  private:
  const std::string& _internal_out() const;
  void _internal_set_out(const std::string& value);
  std::string* _internal_mutable_out();
  public:

  // string err = 3;
  void clear_err();
  const std::string& err() const;
  void set_err(const std::string& value);
  void set_err(std::string&& value);
  void set_err(const char* value);
  void set_err(const char* value, size_t size);
  std::string* mutable_err();
  std::string* release_err();
  void set_allocated_err(std::string* err);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_err();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_err(
      std::string* err);
  private:
  const std::string& _internal_err() const;
  void _internal_set_err(const std::string& value);
  std::string* _internal_mutable_err();
  public:

  // @@protoc_insertion_point(class_scope:reverse.std)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr in_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr out_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr err_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_coms_2eproto;
};
// -------------------------------------------------------------------

class reverseRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:reverse.reverseRequest) */ {
 public:
  inline reverseRequest() : reverseRequest(nullptr) {};
  virtual ~reverseRequest();

  reverseRequest(const reverseRequest& from);
  reverseRequest(reverseRequest&& from) noexcept
    : reverseRequest() {
    *this = ::std::move(from);
  }

  inline reverseRequest& operator=(const reverseRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline reverseRequest& operator=(reverseRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const reverseRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const reverseRequest* internal_default_instance() {
    return reinterpret_cast<const reverseRequest*>(
               &_reverseRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(reverseRequest& a, reverseRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(reverseRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(reverseRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline reverseRequest* New() const final {
    return CreateMaybeMessage<reverseRequest>(nullptr);
  }

  reverseRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<reverseRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const reverseRequest& from);
  void MergeFrom(const reverseRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(reverseRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "reverse.reverseRequest";
  }
  protected:
  explicit reverseRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_coms_2eproto);
    return ::descriptor_table_coms_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStdFieldNumber = 1,
  };
  // .reverse.std std = 1;
  bool has_std() const;
  private:
  bool _internal_has_std() const;
  public:
  void clear_std();
  const ::reverse::std& std() const;
  ::reverse::std* release_std();
  ::reverse::std* mutable_std();
  void set_allocated_std(::reverse::std* std);
  private:
  const ::reverse::std& _internal_std() const;
  ::reverse::std* _internal_mutable_std();
  public:
  void unsafe_arena_set_allocated_std(
      ::reverse::std* std);
  ::reverse::std* unsafe_arena_release_std();

  // @@protoc_insertion_point(class_scope:reverse.reverseRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::reverse::std* std_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_coms_2eproto;
};
// -------------------------------------------------------------------

class reverseResponse PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:reverse.reverseResponse) */ {
 public:
  inline reverseResponse() : reverseResponse(nullptr) {};
  virtual ~reverseResponse();

  reverseResponse(const reverseResponse& from);
  reverseResponse(reverseResponse&& from) noexcept
    : reverseResponse() {
    *this = ::std::move(from);
  }

  inline reverseResponse& operator=(const reverseResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline reverseResponse& operator=(reverseResponse&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const reverseResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const reverseResponse* internal_default_instance() {
    return reinterpret_cast<const reverseResponse*>(
               &_reverseResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(reverseResponse& a, reverseResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(reverseResponse* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(reverseResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline reverseResponse* New() const final {
    return CreateMaybeMessage<reverseResponse>(nullptr);
  }

  reverseResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<reverseResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const reverseResponse& from);
  void MergeFrom(const reverseResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(reverseResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "reverse.reverseResponse";
  }
  protected:
  explicit reverseResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_coms_2eproto);
    return ::descriptor_table_coms_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStdFieldNumber = 1,
  };
  // .reverse.std std = 1;
  bool has_std() const;
  private:
  bool _internal_has_std() const;
  public:
  void clear_std();
  const ::reverse::std& std() const;
  ::reverse::std* release_std();
  ::reverse::std* mutable_std();
  void set_allocated_std(::reverse::std* std);
  private:
  const ::reverse::std& _internal_std() const;
  ::reverse::std* _internal_mutable_std();
  public:
  void unsafe_arena_set_allocated_std(
      ::reverse::std* std);
  ::reverse::std* unsafe_arena_release_std();

  // @@protoc_insertion_point(class_scope:reverse.reverseResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::reverse::std* std_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_coms_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// std

// string in = 1;
inline void std::clear_in() {
  in_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& std::in() const {
  // @@protoc_insertion_point(field_get:reverse.std.in)
  return _internal_in();
}
inline void std::set_in(const std::string& value) {
  _internal_set_in(value);
  // @@protoc_insertion_point(field_set:reverse.std.in)
}
inline std::string* std::mutable_in() {
  // @@protoc_insertion_point(field_mutable:reverse.std.in)
  return _internal_mutable_in();
}
inline const std::string& std::_internal_in() const {
  return in_.Get();
}
inline void std::_internal_set_in(const std::string& value) {
  
  in_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void std::set_in(std::string&& value) {
  
  in_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:reverse.std.in)
}
inline void std::set_in(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  in_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:reverse.std.in)
}
inline void std::set_in(const char* value,
    size_t size) {
  
  in_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:reverse.std.in)
}
inline std::string* std::_internal_mutable_in() {
  
  return in_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* std::release_in() {
  // @@protoc_insertion_point(field_release:reverse.std.in)
  return in_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void std::set_allocated_in(std::string* in) {
  if (in != nullptr) {
    
  } else {
    
  }
  in_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), in,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:reverse.std.in)
}
inline std::string* std::unsafe_arena_release_in() {
  // @@protoc_insertion_point(field_unsafe_arena_release:reverse.std.in)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return in_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void std::unsafe_arena_set_allocated_in(
    std::string* in) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (in != nullptr) {
    
  } else {
    
  }
  in_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      in, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:reverse.std.in)
}

// string out = 2;
inline void std::clear_out() {
  out_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& std::out() const {
  // @@protoc_insertion_point(field_get:reverse.std.out)
  return _internal_out();
}
inline void std::set_out(const std::string& value) {
  _internal_set_out(value);
  // @@protoc_insertion_point(field_set:reverse.std.out)
}
inline std::string* std::mutable_out() {
  // @@protoc_insertion_point(field_mutable:reverse.std.out)
  return _internal_mutable_out();
}
inline const std::string& std::_internal_out() const {
  return out_.Get();
}
inline void std::_internal_set_out(const std::string& value) {
  
  out_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void std::set_out(std::string&& value) {
  
  out_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:reverse.std.out)
}
inline void std::set_out(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  out_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:reverse.std.out)
}
inline void std::set_out(const char* value,
    size_t size) {
  
  out_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:reverse.std.out)
}
inline std::string* std::_internal_mutable_out() {
  
  return out_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* std::release_out() {
  // @@protoc_insertion_point(field_release:reverse.std.out)
  return out_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void std::set_allocated_out(std::string* out) {
  if (out != nullptr) {
    
  } else {
    
  }
  out_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), out,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:reverse.std.out)
}
inline std::string* std::unsafe_arena_release_out() {
  // @@protoc_insertion_point(field_unsafe_arena_release:reverse.std.out)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return out_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void std::unsafe_arena_set_allocated_out(
    std::string* out) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (out != nullptr) {
    
  } else {
    
  }
  out_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      out, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:reverse.std.out)
}

// string err = 3;
inline void std::clear_err() {
  err_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& std::err() const {
  // @@protoc_insertion_point(field_get:reverse.std.err)
  return _internal_err();
}
inline void std::set_err(const std::string& value) {
  _internal_set_err(value);
  // @@protoc_insertion_point(field_set:reverse.std.err)
}
inline std::string* std::mutable_err() {
  // @@protoc_insertion_point(field_mutable:reverse.std.err)
  return _internal_mutable_err();
}
inline const std::string& std::_internal_err() const {
  return err_.Get();
}
inline void std::_internal_set_err(const std::string& value) {
  
  err_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void std::set_err(std::string&& value) {
  
  err_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:reverse.std.err)
}
inline void std::set_err(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  err_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:reverse.std.err)
}
inline void std::set_err(const char* value,
    size_t size) {
  
  err_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:reverse.std.err)
}
inline std::string* std::_internal_mutable_err() {
  
  return err_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* std::release_err() {
  // @@protoc_insertion_point(field_release:reverse.std.err)
  return err_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void std::set_allocated_err(std::string* err) {
  if (err != nullptr) {
    
  } else {
    
  }
  err_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), err,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:reverse.std.err)
}
inline std::string* std::unsafe_arena_release_err() {
  // @@protoc_insertion_point(field_unsafe_arena_release:reverse.std.err)
  GOOGLE_DCHECK(GetArena() != nullptr);
  
  return err_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArena());
}
inline void std::unsafe_arena_set_allocated_err(
    std::string* err) {
  GOOGLE_DCHECK(GetArena() != nullptr);
  if (err != nullptr) {
    
  } else {
    
  }
  err_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      err, GetArena());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:reverse.std.err)
}

// -------------------------------------------------------------------

// reverseRequest

// .reverse.std std = 1;
inline bool reverseRequest::_internal_has_std() const {
  return this != internal_default_instance() && std_ != nullptr;
}
inline bool reverseRequest::has_std() const {
  return _internal_has_std();
}
inline void reverseRequest::clear_std() {
  if (GetArena() == nullptr && std_ != nullptr) {
    delete std_;
  }
  std_ = nullptr;
}
inline const ::reverse::std& reverseRequest::_internal_std() const {
  const ::reverse::std* p = std_;
  return p != nullptr ? *p : *reinterpret_cast<const ::reverse::std*>(
      &::reverse::_std_default_instance_);
}
inline const ::reverse::std& reverseRequest::std() const {
  // @@protoc_insertion_point(field_get:reverse.reverseRequest.std)
  return _internal_std();
}
inline void reverseRequest::unsafe_arena_set_allocated_std(
    ::reverse::std* std) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(std_);
  }
  std_ = std;
  if (std) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:reverse.reverseRequest.std)
}
inline ::reverse::std* reverseRequest::release_std() {
  auto temp = unsafe_arena_release_std();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::reverse::std* reverseRequest::unsafe_arena_release_std() {
  // @@protoc_insertion_point(field_release:reverse.reverseRequest.std)
  
  ::reverse::std* temp = std_;
  std_ = nullptr;
  return temp;
}
inline ::reverse::std* reverseRequest::_internal_mutable_std() {
  
  if (std_ == nullptr) {
    auto* p = CreateMaybeMessage<::reverse::std>(GetArena());
    std_ = p;
  }
  return std_;
}
inline ::reverse::std* reverseRequest::mutable_std() {
  // @@protoc_insertion_point(field_mutable:reverse.reverseRequest.std)
  return _internal_mutable_std();
}
inline void reverseRequest::set_allocated_std(::reverse::std* std) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete std_;
  }
  if (std) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(std);
    if (message_arena != submessage_arena) {
      std = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, std, submessage_arena);
    }
    
  } else {
    
  }
  std_ = std;
  // @@protoc_insertion_point(field_set_allocated:reverse.reverseRequest.std)
}

// -------------------------------------------------------------------

// reverseResponse

// .reverse.std std = 1;
inline bool reverseResponse::_internal_has_std() const {
  return this != internal_default_instance() && std_ != nullptr;
}
inline bool reverseResponse::has_std() const {
  return _internal_has_std();
}
inline void reverseResponse::clear_std() {
  if (GetArena() == nullptr && std_ != nullptr) {
    delete std_;
  }
  std_ = nullptr;
}
inline const ::reverse::std& reverseResponse::_internal_std() const {
  const ::reverse::std* p = std_;
  return p != nullptr ? *p : *reinterpret_cast<const ::reverse::std*>(
      &::reverse::_std_default_instance_);
}
inline const ::reverse::std& reverseResponse::std() const {
  // @@protoc_insertion_point(field_get:reverse.reverseResponse.std)
  return _internal_std();
}
inline void reverseResponse::unsafe_arena_set_allocated_std(
    ::reverse::std* std) {
  if (GetArena() == nullptr) {
    delete reinterpret_cast<::PROTOBUF_NAMESPACE_ID::MessageLite*>(std_);
  }
  std_ = std;
  if (std) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:reverse.reverseResponse.std)
}
inline ::reverse::std* reverseResponse::release_std() {
  auto temp = unsafe_arena_release_std();
  if (GetArena() != nullptr) {
    temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
  }
  return temp;
}
inline ::reverse::std* reverseResponse::unsafe_arena_release_std() {
  // @@protoc_insertion_point(field_release:reverse.reverseResponse.std)
  
  ::reverse::std* temp = std_;
  std_ = nullptr;
  return temp;
}
inline ::reverse::std* reverseResponse::_internal_mutable_std() {
  
  if (std_ == nullptr) {
    auto* p = CreateMaybeMessage<::reverse::std>(GetArena());
    std_ = p;
  }
  return std_;
}
inline ::reverse::std* reverseResponse::mutable_std() {
  // @@protoc_insertion_point(field_mutable:reverse.reverseResponse.std)
  return _internal_mutable_std();
}
inline void reverseResponse::set_allocated_std(::reverse::std* std) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArena();
  if (message_arena == nullptr) {
    delete std_;
  }
  if (std) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena =
      ::PROTOBUF_NAMESPACE_ID::Arena::GetArena(std);
    if (message_arena != submessage_arena) {
      std = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, std, submessage_arena);
    }
    
  } else {
    
  }
  std_ = std;
  // @@protoc_insertion_point(field_set_allocated:reverse.reverseResponse.std)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace reverse

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_coms_2eproto