#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int left, int right) {
    if (left >= right) return;
    int pivot = left;
    int i = left + 1;
    int j = right;
    int temp;
    while (i <= j) {
        while (i <= right && arr[i] <= arr[pivot]) i++;
        while (j > left && arr[j] >= arr[pivot]) j--;
        if (i > j) {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        } else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    quick_sort(arr, left, j-1);
    quick_sort(arr, j+1, right);
}

int main() {
    int n,k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quick_sort(arr, 0, n-1);
    printf("%d\n", arr[k-1]);
}