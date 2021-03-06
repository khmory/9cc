#include "9cc.h"

int main(int argc, char **argv) {
  if (argc >= 4)
    error("%s: invalid number of arguments", argv[0]);
  if (argc == 3 && strcmp(argv[2], "-d") == 0)
    debug = true;

  user_input = argv[1];
  token = tokenize();

  // トークン列のデバッグ出力
  if (debug)
    token_walk();

  program();

  // アセンブリの前半部分を出力
  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  // プロローグ
  printf("  push rbp\n");
  printf("  mov rbp, rsp\n");
  printf("  sub rsp, 208\n");

  // 先頭の式から順にコード生成
  for (int i = 0; code[i]; i++) {
    gen(code[i]);

    // 式の評価結果としてスタックに一つの値が残っている
    // はずなので、スタックが溢れないようにポップしておく
    printf("  pop rax\n");
  }

  // エピローグ
  // 最後の式の結果がRAXに残っているのでそれが返り値となる
  printf("  mov rsp, rbp\n");
  printf("  pop rbp\n");
  printf("  ret\n");
  return 0;
}
