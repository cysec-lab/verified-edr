/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix ParseSpeed -no-prefix ParseIndicator -no-prefix ParseDoor parseSpeed.fst parseIndicator.fst parseDoor.fst
  F* version: <unknown>
  KreMLin version: bf7d50e8
 */

#ifndef __ParseDoor_H
#define __ParseDoor_H

#include "kremlib.h"




typedef struct struct_error1_s
{
  int32_t code;
  C_String_t message;
}
struct_error1;

int32_t __proj__Mkstruct_error__item__code1(struct_error1 projectee);

C_String_t __proj__Mkstruct_error__item__message1(struct_error1 projectee);

typedef struct fstar_uint80_s
{
  uint8_t value;
  struct_error1 error;
}
fstar_uint80;

uint8_t __proj__Mkfstar_uint8__item__value0(fstar_uint80 projectee);

struct_error1 __proj__Mkfstar_uint8__item__error0(fstar_uint80 projectee);

fstar_uint80 parseDoor_body(uint32_t can_id, uint8_t can_dlc, uint8_t *data);

fstar_uint80 parseDoor(uint32_t can_id, uint8_t can_dlc, uint8_t *data);


#define __ParseDoor_H_DEFINED
#endif
