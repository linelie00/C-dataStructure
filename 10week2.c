#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 1001

int N, M, V;
int graph[MAX_VERTEX][MAX_VERTEX];
int visit[MAX_VERTEX];

void dfs(int v) {
    printf("%d ", v);
    visit[v] = 1;
    for (int i = 1; i <= N; i++) {
        if (visit[i] == 1 || graph[v][i] == 0)
            continue;
        dfs(i);
    }
}

void bfs(int v) {
    int queue[MAX_VERTEX];
    int front = 0, rear = 0;
    int pop;
    printf("%d ", v);
    queue[0] = v;
    rear++;
    visit[v] = 0;
    while (front < rear) {
        pop = queue[front];
        front++;
        for (int i = 1; i <= N; i++) {
            if (visit[i] == 0 || graph[pop][i] == 0)
                continue;
            printf("%d ", i);
            queue[rear] = i;
            rear++;
            visit[i] = 0;
        }
    }
}

int main() {
    int x, y;
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = graph[y][x] = 1;
    }
    dfs(V);
    printf("\n");
    bfs(V);
    printf("\n");
    return 0;
}
