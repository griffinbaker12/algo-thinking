#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINES 100

int shortest_line_index(int lines[]) {
    int shortest = 0;
    return 1;
}

void solve(int lines[], int n, int m) {
    int i, shortest;
    for (i = 0; i < m; i++) {
        shortest = shortest_line_index();
        lines[shortest]++;
    }
}

int main() {
    int lines[MAX_LINES];
    int n, m, i;
    // interesting, this will automatically parse for integers from stdin
    scanf("%d%d", &n, &m);
    printf("%d, %d", n, m);
    // so there are n lines, and number of new people (get added to least
    // populated line)
    for (i = 0; i < n; i++) {
        scanf("%d", &lines[i]);
    }
    solve(lines, n, m);
    return 0;
}
