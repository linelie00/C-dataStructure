#include <stdio.h>

#define MAX_LEVEL 50
#define MAX_WIDTH 40
char screen[MAX_LEVEL][MAX_WIDTH];

void initialize_screen() {
    for (int i = 0; i < MAX_LEVEL; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            screen[i][j] = '-';
        }
    }
}

void draw_tree(int row, int left, int right) {
    if (right - left < 3)
        return;

    int middle = (left + right) / 2;
    screen[row][middle] = 'X';

    draw_tree(row + 1, left, middle);
    draw_tree(row + 1, middle, right);
}

void print_screen() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            printf("%c", screen[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_screen();
    draw_tree(0, 0, MAX_WIDTH);
    print_screen();

    return 0;
}
