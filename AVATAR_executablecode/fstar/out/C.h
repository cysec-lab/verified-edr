/* 
  This file was generated by KreMLin <https://github.com/FStarLang/kremlin>
  KreMLin invocation: krml -verify -warn-error +9 -drop WasmSupport -tmpdir ./out -fsopt --cache_dir -fsopt ./out -fsopt --cache_checked_modules -skip-linking -skip-compilation -no-prefix ParseSpeed -no-prefix ParseIndicator -no-prefix ParseDoor parseSpeed.fst parseIndicator.fst parseDoor.fst
  F* version: <unknown>
  KreMLin version: bf7d50e8
 */

#ifndef __C_H
#define __C_H

#include "kremlib.h"




extern void portable_exit(int32_t uu___);

extern char char_of_uint8(uint8_t uu___);

extern uint8_t uint8_of_char(char uu___);

bool uu___is_EXIT_SUCCESS(exit_code projectee);

bool uu___is_EXIT_FAILURE(exit_code projectee);

extern void print_bytes(uint8_t *b, uint32_t len);


#define __C_H_DEFINED
#endif
