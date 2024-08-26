#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PWD 10
#define NUM_BITS 20
#define MAX_USERS 100000

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

typedef struct pwd_node {
    char password[MAX_PWD + 1];
    int total;
    struct pwd_node *next;
} pwd_node;

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

void add_to_table(pwd_node *db[], unsigned long hash, char sub_str[]) {
    pwd_node *existing = db[hash];
    if (!existing) {
        existing = malloc(sizeof(pwd_node));
        if (existing == NULL) {
            fprintf(stderr, "malloc err\n");
            return;
        }
        strcpy(existing->password, sub_str);
        existing->total = 1;
        db[hash] = existing;
    } else {
        pwd_node *current = existing;
        while (current != NULL) {
            if (strcmp(current->password, sub_str) == 0) {
                current->total++;
                return;
            }
            current = current->next;
        }
        pwd_node *new_node = malloc(sizeof(pwd_node));
        if (new_node == NULL) {
            fprintf(stderr, "malloc err\n");
            return;
        }
        strcpy(new_node->password, sub_str);
        new_node->total = 1;
        new_node->next = existing;
        db[hash] = new_node;
    }
}

int find_matches(pwd_node *db[], char s[]) {
    unsigned long hash = oaat(s, strlen(s), NUM_BITS);
    pwd_node *curr = db[hash];
    while (curr != NULL) {
        if (strcmp(curr->password, s) == 0) {
            return curr->total;
        }
        curr = curr->next;
    }
    return 0;
}

// so what we want to do is store all of the
// pwds, and then store all of the substrings,
// ensuring that we don't double search for
// the substrings
int main() {
    int i, num_ops, op;
    unsigned long hash;
    char password[MAX_PWD + 1];
    static pwd_node *db[1 << NUM_BITS] = {NULL};
    scanf("%d", &num_ops);
    for (i = 0; i < num_ops; i++) {
        scanf("%d%s", &op, password);
        if (op == 1) {
            int j, k, pwd_len, sub_str_len, sub_str_amt;
            sub_str_amt = 0;
            char sub_strs[MAX_PWD * MAX_PWD][MAX_PWD + 1];
            pwd_len = strlen(password);
            for (j = 0; j < pwd_len; j++) {
                for (k = j; k < pwd_len; k++) {
                    sub_str_len = k - j + 1;
                    char sub_str[sub_str_len];
                    strncpy(sub_str, &password[j], sub_str_len);
                    sub_str[sub_str_len] = '\0';
                    int exists = 0;
                    for (int l = 0; l < sub_str_amt; ++l) {
                        if (strcmp(sub_str, sub_strs[l]) == 0) {
                            exists = 1;
                            break;
                        }
                    }
                    if (!exists) {
                        strcpy(sub_strs[sub_str_amt++], sub_str);
                        hash = oaat(sub_str, strlen(sub_str), NUM_BITS);
                        add_to_table(db, hash, sub_str);
                    }
                }
            }
        } else {
            printf("%d\n", find_matches(db, password));
        }
    }
}
