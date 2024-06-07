#include <stdio.h>
#include <stdlib.h>

int N, cnt, map[25][25], visit[25][25], dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}, ans[313];

void dfs(int x, int y) {
    visit[x][y] = 1;
    ans[cnt]++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < N && 0 <= ny && ny < N)
            if (map[nx][ny] && !visit[nx][ny])
                dfs(nx, ny);
    }
}

int compare(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2)
        return -1;
    if (num1 > num2)
        return 1;
    return 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%1d", &map[i][j]);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (map[i][j] && !visit[i][j]) {
                dfs(i, j);
                cnt++;
            }
    qsort(ans, cnt, sizeof(int), compare);
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
        printf("%d\n", ans[i]);
    return 0;
}
