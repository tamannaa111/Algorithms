#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int v[MAX_NODES][MAX_NODES]; // Adjacency matrix to represent the graph
int vis[MAX_NODES];

int stack[MAX_NODES];
int top = -1;

void push(int item) {
    if (top == MAX_NODES - 1) {
        printf("Stack is full.\n");
        exit(1);
    }
    stack[++top] = item;
}

int pop() {
    if (top == -1) {
        printf("Stack is empty.\n");
        exit(1);
    }
    return stack[top--];
}

void dfs(int source, int n) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    push(source);
    while (top != -1) {
        int x = pop();
        if (vis[x] == 0) {
            vis[x] = 1;
            printf("%d ", x);
            for (int a = 1; a <= n; a++) {
                if (v[x][a] && vis[a] == 0) {
                    push(a);
                }
            }
        }
    }
}

int main() {
    int m, n, x, y, s;
    printf("Enter number of nodes and edges:\n");
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y); // x and y node no
        v[x][y] = 1;
        v[y][x] = 1;
    }

    for (int i = 1; i <= n; i++) {
        printf("The adjacent list of %d -> are ", i);
        for (int j = 1; j <= n; j++) {
            if (v[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    printf("Enter the source node: ");
    scanf("%d", &s);
    printf("The DFS traversal:\n");
    dfs(s, n);

    return 0;
}
