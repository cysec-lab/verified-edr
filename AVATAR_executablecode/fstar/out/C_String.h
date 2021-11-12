/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix HardCoding -no-prefix ParseDoor -no-prefix ParseIndicator -no-prefix ParseSpeed hardCoding.fst parseDoor.fst parseIndicator.fst parseSpeed.fst
  F* version: <unknown>
  KreMLin version: 9bc903e0
 */

#ifndef __C_String_H
#define __C_String_H

#include "kremlib.h"




extern void C_String_print(C_String_t uu___);

extern uint32_t C_String_strlen(C_String_t s);

extern void C_String_memcpy(uint8_t *dst, C_String_t src, uint32_t n);


#define __C_String_H_DEFINED
#endif
