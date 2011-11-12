#include <dlfcn.h>
#include <stdio.h>

int main(int argc, char **argv)
{
  void (*sl1)();
  void *s;
  void * h = dlopen("../testlib/libsl1.so", RTLD_NOW);
  if (h == 0) {
    fprintf(stderr, "%s\n", dlerror());
    return 1;
  }
  s = dlsym(h, "sl1");
  if (s == 0) {
    fprintf(stderr, "%s\n", dlerror());
    return 1;
  }
  sl1 = s;
  (*sl1)();

  h = dlopen("../testlib/libsl1noorigin.so", RTLD_NOW);
  if (h == 0) {
    fprintf(stderr, "error loading libsl1noorigin %s\n", dlerror());
    return 1;
  }
  s = dlsym(h, "sl1");
  if (s == 0) {
    fprintf(stderr, "error finding sl1 in libsl1noorigin %s\n", dlerror());
    return 1;
  }
  sl1 = s;
  (*sl1)();

  return 0;
}
