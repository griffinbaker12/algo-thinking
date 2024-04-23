#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recursively create substrings starting from each position in the
// string.
char** create_substrings(char* str, int* count)
{
    int length = strlen(str);
    *count = (length * (length + 1)) / 2; // Calculate the number of substrings

    // Allocate memory for the array of pointers to substrings
    char** substrings = malloc(*count * sizeof(char*));
    if (substrings == NULL) {
        perror("Failed to allocate memory for substring array");
        return NULL;
    }

    int index = 0;
    for (int start = 0; start < length; start++) {
        for (int end = start + 1; end <= length; end++) {
            int substr_length = end - start;
            substrings[index] = malloc((substr_length + 1) * sizeof(char)); // +1 for null terminator
            if (substrings[index] == NULL) {
                perror("Failed to allocate memory for a substring");
                // Cleanup already allocated memory before returning
                while (--index >= 0) {
                    free(substrings[index]);
                }
                free(substrings);
                return NULL;
            }
            memcpy(substrings[index], &str[start], substr_length);
            substrings[index][substr_length] = '\0'; // Null-terminate the substring
            index++;
        }
    }
    return substrings;
}

int main()
{
    char str[] = "abc"; // Input string
    int length = strlen(str); // Calculate the length of the string
    printf("%d\n", length); // Removes the terminating char
                            //
    // strdu

    return 0;
}
