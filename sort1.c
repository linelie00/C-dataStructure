#include <stdio.h>

// 배열을 분할하고 피벗의 최종 위치를 반환하는 함수
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // 피벗을 배열의 마지막 요소로 선택
    int i = (low - 1); // 작은 요소의 인덱스

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; // 작은 요소의 인덱스 증가
            // arr[i]와 arr[j] 교환
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // arr[i + 1]과 arr[high] (또는 피벗) 교환
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// 퀵정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // 파티션 인덱스 pi는 피벗의 올바른 위치를 나타냄
        int pi = partition(arr, low, high);

        // pi를 기준으로 왼쪽과 오른쪽 부분 배열을 각각 정렬
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 배열 출력 함수
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Given array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
