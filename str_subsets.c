#include <stdio.h>
#include <string.h>

// Function to recursively create substrings starting from each position in the
// string.
void create_substrings(char *str, int start, int length) {
  if (start >= length)
    return;

  char output[length + 1];

  for (int i = start + 1; i <= length; i++) {
    memcpy(output, &str[start], i - start);
    output[i - start] = '\0';
    printf("%s\n", output);
  }

  create_substrings(str, start + 1, length);
}

int main() {
  char str[] = "abc";       // Input string
  int length = strlen(str); // Calculate the length of the string
  printf("%d\n", length);   // Removes the terminating char

  create_substrings(
      str, 0, length); // Start generating substrings from the first position

  return 0;
}
