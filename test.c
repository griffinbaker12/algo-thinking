#include <stdio.h>

int TIMES_TO_CALL = 5;

int f(void) {
  static int i = 0;
  printf("f() called %d times\n", ++i);
  return i;
}

int main() {
  printf("Hello, World!\n");

  for (int i = 0; i < TIMES_TO_CALL; i++) {
    f();
  }

  return 0;
}
