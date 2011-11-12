#include "test_TestNative.h"
#include <stdio.h>

extern void sl2();

void JNICALL Java_test_TestNative_testNative(JNIEnv * env, jclass clazz) {
  printf("Hello from JNI\n");
  fflush(stdout);
  sl2();
}
