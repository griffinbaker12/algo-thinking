#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PWD 10
#define NUM_BITS 20
#define MAX_USERS 100000

#define hashsize(n) ((unsigned long)1 << (n))
#define hashmask(n) (hashsize(n) - 1)

typedef struct password_node {
    char password[MAX_PWD + 1];
    int total;
    struct password_node *next;
} password_node;

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

password_node *in_hash_table(password_node *hash_table[], char *find) {
    unsigned password_code;
    password_node *password_ptr;
    password_code = oaat(find, strlen(find), NUM_BITS);
    password_ptr = hash_table[password_code];
    while (password_ptr) {
        if (strcmp(password_ptr->password, find) == 0)
            return password_ptr;
        password_ptr = password_ptr->next;
    }
    return NULL;
}

// hash table of password_nodes, and we generate a hash based on the pwd to
// determine where to store it
void add_to_hash_table(password_node *hash_table[], char *find) {
    // generate hash for the password
    unsigned hashed_pwd = oaat(find, strlen(find), NUM_BITS);

    // allocate because we will increment at end
    password_node *password_ptr = in_hash_table(hash_table, find);

    // only add if there was not already a match here (SMART!)
    if (!password_ptr) {
        unsigned password_code = oaat(find, strlen(find), NUM_BITS);
        password_ptr = malloc(sizeof(password_node));
        strcpy(password_ptr->password, find);
        password_ptr->next = hash_table[password_code];
        password_ptr->total = 0;
        hash_table[password_code] = password_ptr;
    }

    password_ptr->total++;
    printf("the total for %s is now: %d\n", find, password_ptr->total);
}

int already_added(char substrings[][MAX_PWD + 1], int total_substrings,
                  char *find) {
    for (int i = 0; i < total_substrings; i++) {
        if (strcmp(substrings[i], find) == 0)
            return 1;
    }
    return 0;
}

int main(void) {
    // without static, we get seg fault
    static password_node *hash_table[1 << NUM_BITS] = {NULL};

    int num_ops, op_num;
    char password[MAX_PWD + 1], substring[MAX_PWD + 1];
    password_node *password_ptr;

    printf("How many operations are we supporting?\n");
    scanf("%d", &num_ops);

    char substrings[MAX_PWD * MAX_PWD][MAX_PWD + 1];

    for (int i = 0; i < num_ops; i++) {
        // password is already mem location
        scanf("%d%s", &op_num, password);
        if (op_num == 1) {
            // so we need to generate all the possible substrings and make sure
            // that we have not added that substring yet because there may be
            // duplicates
            int total_substrings = 0;
            for (int i = 0; i < strlen(password); i++) {
                // need this +1 for the terminating case
                for (int j = i; j < strlen(password); j++) {
                    char current_pwd[MAX_PWD + 1];
                    strncpy(current_pwd, &password[i], j - i + 1);
                    current_pwd[j - i + 1] = '\0';
                    // make sure we have not added this substring yet for this
                    // current password
                    if (!already_added(substrings, total_substrings,
                                       current_pwd)) {
                        add_to_hash_table(hash_table, current_pwd);
                        printf("added: %s\n", current_pwd);
                        strcpy(substrings[total_substrings], current_pwd);
                        total_substrings++;
                    }
                }
            }
        } else {
            // check how many others we have with the same password already in
            // the table
            password_ptr = in_hash_table(hash_table, password);
            if (!password_ptr) {
                printf("0\n");
            } else {
                printf("%d\n", password_ptr->total);
            }
        }
    }
}
