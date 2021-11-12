/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix HardCoding -no-prefix ParseDoor -no-prefix ParseIndicator -no-prefix ParseSpeed hardCoding.fst parseDoor.fst parseIndicator.fst parseSpeed.fst
  F* version: <unknown>
  KreMLin version: 9bc903e0
 */

#ifndef __ParseIndicator_H
#define __ParseIndicator_H

#include "kremlib.h"


#include "HardCoding.h"
#include "ParseDoor.h"

fstar_uint8 parseIndicator_body(uint32_t can_id, uint8_t can_dlc, uint8_t *data);

fstar_uint8 parseIndicator(uint32_t can_id, uint8_t can_dlc, uint8_t *data);


#define __ParseIndicator_H_DEFINED
#endif
