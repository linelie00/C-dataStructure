#include <stdio.h>
#include <stdlib.h>

void bfs(int N, int M, int maze[N][M]){
    int queue[N*M][2]; // 0: x, 1: y
    int front = 0;
    int rear = 0;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    queue[rear][0] = 0;
    queue[rear++][1] = 0;
    while(front<rear){
        int x = queue[front][0];
        int y = queue[front++][1];
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && maze[nx][ny]==1){
                maze[nx][ny] = maze[x][y] + 1;
                queue[rear][0] = nx;
                queue[rear++][1] = ny;
            }
        }
    }
    printf("%d\n", maze[N-1][M-1]);
}


int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int maze[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%1d", &maze[i][j]);
        }
    }
    bfs(N, M, maze);
}