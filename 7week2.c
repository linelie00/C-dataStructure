#include <stdio.h>
#include <stdbool.h>

int N;
int answer = 0;
bool cols[15];  // 각 열에 퀸이 놓여있는지 여부
bool diag1[30]; // 대각선 방향(\)에 퀸이 놓여있는지 여부
bool diag2[30]; // 대각선 방향(/)에 퀸이 놓여있는지 여부

void solve(int row) {
    if (row == N) {
        answer++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (!cols[col] && !diag1[row + col] && !diag2[row - col + N - 1]) {
            cols[col] = true;
            diag1[row + col] = true;
            diag2[row - col + N - 1] = true;
            solve(row + 1);
            cols[col] = false;
            diag1[row + col] = false;
            diag2[row - col + N - 1] = false;
        }
    }
}

int main() {
    scanf("%d", &N);

    solve(0);

    printf("%d\n", answer);

    return 0;
}
