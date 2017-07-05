// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: msg_error.proto

#ifndef PROTOBUF_msg_5ferror_2eproto__INCLUDED
#define PROTOBUF_msg_5ferror_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_msg_5ferror_2eproto();
void protobuf_AssignDesc_msg_5ferror_2eproto();
void protobuf_ShutdownFile_msg_5ferror_2eproto();


enum SERR {
  SERR_OK = 0,
  SERR_Exception = 1,
  SERR_Msg = 2,
  SERR_Notplt = 3,
  SERR_Illegal = 4,
  SERR_Arg = 5,
  SERR_State = 6,
  SERR_Remote = 7,
  SERR_Noacc = 8,
  SERR_Passwd = 9,
  SERR_InvalidName = 10,
  SERR_ExistName = 11,
  SERR_NameChanged = 12,
  SERR_Nocopper = 21,
  SERR_Nogold = 22,
  SERR_Noticket = 23,
  SERR_Nomat = 30,
  SERR_Norole = 31,
  SERR_Notfriend = 80,
  SERR_Friendyet = 81,
  SERR_HasInvite = 82,
  SERR_Blackyet = 83,
  SERR_FightGone = 84,
  SERR_ReenterFight = 85,
  SERR_ExitFight = 86
};
bool SERR_IsValid(int value);
const SERR SERR_MIN = SERR_OK;
const SERR SERR_MAX = SERR_ExitFight;
const int SERR_ARRAYSIZE = SERR_MAX + 1;

const ::google::protobuf::EnumDescriptor* SERR_descriptor();
inline const ::std::string& SERR_Name(SERR value) {
  return ::google::protobuf::internal::NameOfEnum(
    SERR_descriptor(), value);
}
inline bool SERR_Parse(
    const ::std::string& name, SERR* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SERR>(
    SERR_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {

template <>
inline const EnumDescriptor* GetEnumDescriptor< ::SERR>() {
  return ::SERR_descriptor();
}

}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_msg_5ferror_2eproto__INCLUDED