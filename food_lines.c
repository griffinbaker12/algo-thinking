#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100000
#define SNOWFLAKE_LEN 6

typedef struct snowflake_node {
  // store data
  int snowflake[6];
  // next flake
  struct snowflake_node *next;
} snowflake_node;

int code(int snowflake[]) {
  int sum = 0, i;
  for (i = 0; i < SNOWFLAKE_LEN; i++) {
    sum += snowflake[i];
  }
  // keep it inside the array range
  return sum % SIZE;
}

int identify_left(int snow1[], int snow2[], int start) {
  for (int i = 0; i < SNOWFLAKE_LEN; i++) {
    // you want -1 to be 6
    int index = start - i;
    if (index <= -1)
      index = index + SNOWFLAKE_LEN;
    if (snow1[i] != snow2[index])
      return 0;
  }
  return 1;
}

int identify_right(int snow1[], int snow2[], int start) {
  for (int i = 0; i < SNOWFLAKE_LEN; i++) {
    if (snow1[i] != snow2[(i + start) % SNOWFLAKE_LEN]) {
      return 0;
    }
  }
  return 1;
}

int are_identical(int snow1[], int snow2[]) {
  for (int i = 0; i < SNOWFLAKE_LEN; i++) {
    if (identify_left(snow1, snow2, i))
      return 1;
    if (identify_right(snow1, snow2, i))
      return 1;
  }
  return 0;
}

void identify_identical(snowflake_node *snowflake_values[]) {
  snowflake_node *node1, *node2;
  // go over entire array of snowflakes
  for (int i = 0; i < SIZE; i++) {
    // iterate lists contained therein
    node1 = snowflake_values[i];
    while (node1 != NULL) {
      node2 = node1->next;
      while (node2 != NULL) {
        if (are_identical(node1->snowflake, node2->snowflake)) {
          printf("Twin snowflakes found.\n");
        }
        node2 = node2->next;
      }
      node1 = node1->next;
    }
  }
  printf("No identical snowflakes found.\n");
}

int main(void) {
  // build up array of pointers to snowflake nodes
  static snowflake_node *snowflakes[SIZE] = {NULL};

  // pointer to a snowflake node
  snowflake_node *snow;

  // read in amount of snowflakes we need to process and read into memory
  // address at n
  int n;
  scanf("%d", &n);

  // FIRST STEP: build up the array of linked lists
  for (int i = 0; i < SIZE; i++) {
    // allocate memory for snowflake node
    snow = malloc(sizeof(snowflake_node));
    if (snow == NULL) {
      // error allocating memory
      fprintf(stderr, "malloc error\n");
      exit(1);
    }
    // read in 6 ints for each snowflake position
    for (int j = 0; j < SNOWFLAKE_LEN; j++) {
      scanf("%d", &snow->snowflake[i]);
    }
    // know get the code for the snowflake we just built up
    int snowflake_code = code(snow->snowflake);
    // add snowflake to the beginning of the list
    // if we switched the order, we would lose the list
    snow->next = snowflakes[snowflake_code];
    snowflakes[snowflake_code] = snow;
  }

  // SECOND STEP: check each array slot for identical values in the lists
  // held therein
  identify_identical(snowflakes);

  return 0;
}
