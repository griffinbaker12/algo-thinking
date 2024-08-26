#include <stdio.h>
#include <string.h>

#define hashsize(n) ((unsigned long)1 << (n))
// flips bits
#define hashmask(n) (hashsize(n) - 1)

unsigned long oaat(char *key, unsigned long len, unsigned long bits) {
    unsigned long hash, i;
    for (hash = 0, i = 0; i < len; i++) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash & hashmask(bits);
}

int main(void) { // sample call of oaat
    char word[] = "hello";
    // 2^17 is the smallest power of 2 that is at least 100000
    unsigned long code = oaat(word, strlen(word), 17);
    printf("%lu\n", code);
    return 0;
}
