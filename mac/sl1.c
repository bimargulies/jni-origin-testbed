#include <stdio.h>

extern void sl2();

void sl1() {
  printf("Hello from SL1\n");
  fflush(stdout);
  sl2();
  return;
}
