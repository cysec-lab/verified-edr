/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix ParseSpeed -no-prefix ParseIndicator -no-prefix ParseDoor parseSpeed.fst parseIndicator.fst parseDoor.fst
  F* version: <unknown>
  KreMLin version: bf7d50e8
 */

#include "ParseSpeed.h"

int32_t __proj__Mkstruct_error__item__code(struct_error projectee)
{
  return projectee.code;
}

C_String_t __proj__Mkstruct_error__item__message(struct_error projectee)
{
  return projectee.message;
}

uint8_t *__proj__Mkfstar_uint8_array__item__value(fstar_uint8_array projectee)
{
  return projectee.value;
}

struct_error __proj__Mkfstar_uint8_array__item__error(fstar_uint8_array projectee)
{
  return projectee.error;
}

fstar_uint8_array parseSpeed_body(uint32_t can_id, uint8_t can_dlc, uint8_t *data)
{
  uint8_t ret[2U] = { 0U };
  ret[0U] = data[0U];
  ret[1U] = data[1U];
  return ((fstar_uint8_array){ .value = ret, .error = { .code = (int32_t)0, .message = "" } });
}

fstar_uint8_array parseSpeed(uint32_t can_id, uint8_t can_dlc, uint8_t *data)
{
  uint8_t v1 = data[1U];
  uint8_t v2 = data[2U];
  uint8_t v3 = data[3U];
  uint8_t v4 = data[4U];
  if
  (
    can_id
    == (uint32_t)0x1b4U
    && can_dlc == (uint8_t)5U
    && v1 >= (uint8_t)0xD0U
    && v2 == (uint8_t)0U
    && v3 == (uint8_t)0U
    && v4 == (uint8_t)0U
  )
    return parseSpeed_body(can_id, can_dlc, data);
  else
    return
      (
        (fstar_uint8_array){
          .value = NULL,
          .error = { .code = (int32_t)1, .message = "invalid arguments" }
        }
      );
}

