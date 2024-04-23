#include <stdio.h>
#include <string.h>

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

  int x = 0, int_result, str_result;
  char input_str[20];

  int_result = scanf("%d", &x);
  str_result = scanf("%s", input_str);

  printf("You entered: %d\n", x);
  printf("The int result is: %d\n", int_result);

  printf("You entered: %s\n", input_str);
  printf("The str result is: %d\n", str_result);
  printf("The length of the str is: %lu\n", strlen(input_str));

  for (int i = 0; i < strlen(input_str); i++) {
    printf("The character at index %d is: %c\n", i, input_str[i]);
  }

  return 0;
}
