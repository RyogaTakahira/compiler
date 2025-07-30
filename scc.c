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

  char *p = argv[1]; //入力文字のポインタ
  char *start = p; //初期ポインタ

  asm_header();
  printf("main: \n");
  printf("  mov $%ld, %%rax\n", strtol(p, &p, 10)); //strtolでポインタ更新
  
  //ポインタが更新されていない場合（数字以外のものが先頭にある [+ or - を除く])
  if(start == p){
    fprintf(stderr, "\033[31m[error]: syntax error '%c'\033[0m\n", *p);
    fprintf(stderr, "Can't use symbols for the first character!\n");
    return 1;
  }

  //あとはnullになるまでくりかえし
  while(*p != '\0'){
    if(*p == '+'){
      p++;
      printf("  add $%ld, %%rax\n", strtol(p, &p, 10));
      continue;
    }
    if(*p == '-'){
      p++;
      printf("  sub $%ld, %%rax\n", strtol(p, &p, 10));
      continue;
    }

    //+ か - 意外だとエラー
    fprintf(stderr, "\033[31m[error]: undefined symbol '%c'\033[0m\n", *p);
    fprintf(stderr, "Can use the symbols \"+\" and \"-\"\n");
    return 1;
  }

  printf("  ret\n");
  asm_footer();

  return 0;
}