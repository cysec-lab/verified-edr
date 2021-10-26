/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix ParseSpeed -no-prefix ParseIndicator -no-prefix ParseDoor parseSpeed.fst parseIndicator.fst parseDoor.fst
  F* version: <unknown>
  KreMLin version: bf7d50e8
 */

#include "ParseIndicator.h"

int32_t __proj__Mkstruct_error__item__code0(struct_error0 projectee)
{
  return projectee.code;
}

C_String_t __proj__Mkstruct_error__item__message0(struct_error0 projectee)
{
  return projectee.message;
}

uint8_t __proj__Mkfstar_uint8__item__value(fstar_uint8 projectee)
{
  return projectee.value;
}

struct_error0 __proj__Mkfstar_uint8__item__error(fstar_uint8 projectee)
{
  return projectee.error;
}

fstar_uint8 parseIndicator_body(uint32_t can_id, uint8_t can_dlc, uint8_t *data)
{
  uint8_t indicatorState = data[0U];
  uint8_t ret = indicatorState;
  if (indicatorState == ret)
    return ((fstar_uint8){ .value = ret, .error = { .code = (int32_t)0, .message = "" } });
  else
    return ((fstar_uint8){ .value = (uint8_t)1U, .error = { .code = (int32_t)1, .message = "" } });
}

fstar_uint8 parseIndicator(uint32_t can_id, uint8_t can_dlc, uint8_t *data)
{
  uint8_t v1 = data[0U];
  uint8_t v2 = data[1U];
  uint8_t v3 = data[2U];
  uint8_t v4 = data[3U];
  if
  (
    can_id
    == (uint32_t)0x188U
    && can_dlc == (uint8_t)4U
    && v1 <= (uint8_t)0x02U
    && v2 == (uint8_t)0U
    && v3 == (uint8_t)0U
    && v4 == (uint8_t)0U
  )
    return parseIndicator_body(can_id, can_dlc, data);
  else
    return
      (
        (fstar_uint8){
          .value = (uint8_t)0U,
          .error = { .code = (int32_t)1, .message = "invalid arguments" }
        }
      );
}

