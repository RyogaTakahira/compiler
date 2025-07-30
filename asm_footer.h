//アセンブラ用フッター
//めんどいから直接ヘッダーファイルに実装
#pragma once

static inline void asm_footer() {
  printf("\n  .section .note.GNU-stack,\"\",@progbits\n");
}