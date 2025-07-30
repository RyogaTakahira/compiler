#include <stdio.h>
#include <stdlib.h>

//アセンブラ用ヘッダ＆フッタ
#include "asm_header.h"
#include "asm_footer.h"

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "argument error\n");
    return 1;
  }

  //メイン部分
  asm_header();
  printf("main:\n");
  printf("  mov $%d, %%rax\n", atoi(argv[1]));
  printf("  ret\n");
  asm_footer();

  return 0;
}