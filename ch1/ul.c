#include <stdio.h>

#define MASK 8
#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

int main() {
    printf("%lu\n", sizeof((unsigned long)1));
    printf("%lu\n", sizeof((int)1));
    printf("%lu\n", hashsize(MASK));
    printf("%lu\n", hashmask(MASK));
}
