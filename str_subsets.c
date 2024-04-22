#include <stdio.h>
#include <string.h>

void create_substrings(char *str, char *output, int start, int next) {
  output[next] = '\0'; // Null-terminate current string

  printf("%s\n", output); // Print the current string

  if (start >= strlen(str)) // Base case: if start index exceeds string length
    return;

  // Include the next character and recurse
  if (str[start] != '\0') {
    output[next] = str[start]; // Set the next character in the output
    create_substrings(str, output, start + 1, next + 1);
  }
}

int main() {
  char str[] = "abc"; // Input string
  char output[6];     // Buffer to hold the current combination

  create_substrings(str, output, 0, 0); // Start generating combinations

  return 0;
}
