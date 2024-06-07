#include <stdio.h>
#include <stdlib.h>

const interporationSearch(int list[], int target, int left, int right) {
    if (left > right) return -1;
    int mid = left + (right - left) * (target - list[left]) / (list[right] - list[left]);
    if (list[mid] == target) return mid;
    else if (list[mid] > target) return interporationSearch(list, target, left, mid - 1);
    else return interporationSearch(list, target, mid + 1, right);
}

int main() {
    int list[] = {1,3,5,7,9,11,13,15,17,19};
    int target;
    scanf("%d", &target);
    int result = interporationSearch(list, target, 0, 9);
    if (result == -1) printf("Key not found\n");
    else printf("Key found at index %d\n", result);
}