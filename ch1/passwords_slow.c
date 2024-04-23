#include "common.h"

#define MAX_USERS 100000
#define MAX_PWD 10

int main(void)
{
    static char users[MAX_USERS][MAX_PWD + 1];
    int num_ops, op_type, total;
    char password[MAX_PWD + 1];
    int num_users = 0;
    printf("How many ops will you support? ");
    scanf("%d", &num_ops);
    for (int op = 0; op < num_ops; op++) {
        printf("Operation number: %d\n", op + 1);
        scanf("%d%s", &op_type, password);
        if (op_type == 1) {
            strcpy(users[num_users], password);
            num_users++;
        } else {
            total = 0;
            for (int j = 0; j < num_users; j++) {
                if (strstr(users[j], password))
                    total++;
            }
            printf("%d\n", total);
        }
    }
    return 0;
}
