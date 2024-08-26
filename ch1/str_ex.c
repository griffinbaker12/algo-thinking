#include <stdio.h>
#include <string.h>
int main() {
    char *c = "hey";
    int s_len = strlen(c);
    printf("%d\n", s_len);
    for (int i = 0; i < s_len; ++i)
        printf("%c", c[i]);
    printf("\n");
    char sub[3];
    for (int i = 0; i < s_len; ++i) {
        for (int j = i; j < s_len; ++j) {
            // oh...this can be an address to any point in the str
            strncpy(sub, &c[i], j - i + 1);
            sub[j - i + 1] = '\0';
            printf("%s\n", sub);
        }
    }
}
