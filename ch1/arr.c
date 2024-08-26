#include <stdio.h>

typedef struct {
    int age;
} person;

int main() {
    // initialized to 0
    static int arr[10];
    for (int i = 0; i < 10; ++i) {
        printf("%d\n", arr[i]);
    }

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    int mat[2][3] = {{1, 2, 3}, {4, 5, 6}};
    printf("%d\n", mat[0][1]);

    static person arr3[10] = {9};
    for (int i = 0; i < 10; ++i)
        printf("%d", arr3[i].age);
}
