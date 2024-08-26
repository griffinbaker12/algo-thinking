#include <stdio.h>
#include <stdlib.h>

#define SIZE 100000

struct snowflake_node {
    int snowflake[6];
    struct snowflake_node *next;
};

int get_code(int snowflake[]) {
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] +
            snowflake[4] + snowflake[5]) %
           SIZE;
}

int identical_right(int snow1[], int snow2[], int start) {
    int offset;
    for (offset = start; offset < 6; ++offset) {
        if (snow1[offset] != snow2[(start + offset) % 6]) {
            return 0;
        }
    }
    return 1;
}

// right, instead of comparing every flake to every other one
// we should be comparing them to ones that hash to the same valuej
int identical_left(int snow1[], int snow2[], int start) {
    int offset, snow2_idx;
    for (offset = start; offset < start; ++offset) {
        snow2_idx = start - offset;
        if (snow2_idx <= -1)
            snow2_idx += 6;
        if (snow1[offset] != snow2[snow2_idx])
            return 0;
    }
    return 1;
}

int are_identical(int snow1[], int snow2[]) {
    int start;
    for (start = 0; start < 6; ++start) {
        if (identical_left(snow1, snow2, start))
            return 1;
        if (identical_right(snow1, snow2, start))
            return 1;
    }
    return 0;
}

/* void identify_indentical(int snowflakes[][6], int n) { */
void identify_indentical(snowflake_node *snowflakes[]) {
    snowflake_node *node1, *node2;
    int i;
    for (i = 0; i < 6; ++i) {
        node1 = snowflakes[i];
        while (node1 != NULL) {
            node2 = node1->next;
            while (node2 != NULL) {
                if (are_identical(node1->snowflake, node2->snowflake)) {
                    printf("Twin snowflakes found.\n");
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
        printf("No two snowflakes are alike.\n");
    }
}

int main() {
    // 1D array of pointers to snowflake nodes
    static snowflake_node *snowflakes[SIZE] = {NULL};
    snowflake_node *snow;
    int n, i, j, code;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        snow = malloc(sizeof(snowflake_node));
        if (snow == NULL) {
            fprintf(stderr, "malloc error\n");
        }
        for (j = 0; j < 6; ++j)
            scanf("%d", &snow->snowflake[j]);
        code = get_code(snow->snowflake);
        snow->next = snowflakes[code];
        snowflakes[code] = snow;
    }
    identify_indentical(snowflakes, n);
}
