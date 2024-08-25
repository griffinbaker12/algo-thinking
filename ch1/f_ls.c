#include <stdio.h>
/* #include <stdlib.h> */
/* #include <string.h> */
/* #include <time.h> */

#define MAX_LINES 100

int shortest_line_idx(int lines[], int n) {
    int shortest = 0;
    for (int i = 1; i < n; ++i)
        if (lines[shortest] > lines[i])
            shortest = i;
    return shortest;
}

void solve(int lines[], int n, int m) {
    int idx_to_add;
    for (int i = 0; i < m; ++i) {
        idx_to_add = shortest_line_idx(lines, n);
        printf("%d\n", lines[idx_to_add]);
        lines[idx_to_add] = lines[idx_to_add] + 1;
    }
}

int main() {
    int lines[MAX_LINES];
    int n, m, i;
    // interesting, this will automatically parse for integers from stdin
    // scanf is always set up to read from stdin
    scanf("%d%d", &n, &m);
    // so there are n lines, and number of new people (get added to least
    // populated line)
    for (i = 0; i < n; i++)
        scanf("%d", &lines[i]);
    solve(lines, n, m);
    return 0;
}
