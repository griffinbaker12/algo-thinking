#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 3; // Suppose we want an array of 3 strings
    char** strings = malloc(n * sizeof(char*)); // Allocate memory for array of pointers

    // Now allocate and assign strings
    strings[0] = strdup("Hello world, this is a string that I am testing to try to see how far this can expand!");
    strings[1] = strdup("World");
    strings[2] = strdup("Neovim");

    // Use the strings
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
        printf("%lu\n", strlen(strings[i]));
    }

    // Free the strings
    for (int i = 0; i < n; i++) {
        free(strings[i]);
    }

    free(strings); // Free the array of pointers

    return 0;
}
