/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix ParseSpeed -no-prefix ParseIndicator -no-prefix ParseDoor -no-prefix HardCoding parseSpeed.fst parseIndicator.fst parseDoor.fst hardCoding.fst
  F* version: <unknown>
  KreMLin version: 9bc903e0
 */

#ifndef __ParseDoor_H
#define __ParseDoor_H

#include "kremlib.h"


#include "HardCoding.h"
#include "ParseIndicator.h"

fstar_uint8 parseDoor_body(uint32_t can_id, uint8_t can_dlc, uint8_t *data);

fstar_uint8 parseDoor(uint32_t can_id, uint8_t can_dlc, uint8_t *data);


#define __ParseDoor_H_DEFINED
#endif
