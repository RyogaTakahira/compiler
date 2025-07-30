//アセンブラ用ヘッダ
//めんどいから直接ヘッダーファイルに実装
#pragma once

static inline void asm_header() {
  printf(".globl main\n");
}