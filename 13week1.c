#include <stdio.h>
#include <stdlib.h>

const binarySearch(int list[], int target, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right) / 2;
    if (list[mid] == target) return mid;
    else if (list[mid] > target) return binarySearch(list, target, left, mid - 1);
    else return binarySearch(list, target, mid + 1, right);
}

int main() {
    int list[] = {1,3,5,7,9,11,13,15,17,19};
    int target;
    scanf("%d", &target);
    int result = binarySearch(list, target, 0, 9);
    if (result == -1) printf("Key not found\n");
    else printf("Key found at index %d\n", result);
}