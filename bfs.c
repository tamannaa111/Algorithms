#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int v[MAX_NODES][MAX_NODES]; // Adjacency matrix to represent the graph
int vis[MAX_NODES];

int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
        exit(1);
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int dequeue() {
    int item;
    if (front == -1) {
        printf("Queue is empty.\n");
        exit(1);
    }
    item = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return item;
}

void bfs(int source, int n) {
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    enqueue(source);
    while (front != -1) {
        int x = dequeue();
        if (vis[x] == 0) {
            vis[x] = 1;
            printf("%d ", x);
            for (int a = 1; a <= n; a++) {
                if (v[x][a] && vis[a] == 0) {
                    enqueue(a);
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
    printf("The BFS traversal:\n");
    bfs(s, n);

    return 0;
}
