#include <stdio.h>
#include <string.h>

#define NAME_SIZE 100

typedef struct {
    int key;
    char name[NAME_SIZE];
} record;

void insertionSort(record arr[], int n) {
    int i, j;
    record key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // arr[j]가 key보다 크면 arr[j + 1]에 arr[j]를 삽입
        while (j >= 0 && arr[j].key > key.key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printRecords(record arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Key: %d, Name: %s\n", arr[i].key, arr[i].name);
    }
}

int main() {
    record arr[] = {
        {5, "Alice"},
        {3, "Bob"},
        {4, "Charlie"},
        {1, "Dave"},
        {2, "Eve"}
    };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("정렬 전 레코드:\n");
    printRecords(arr, n);

    insertionSort(arr, n);

    printf("\n정렬 후 레코드:\n");
    printRecords(arr, n);

    return 0;
}
