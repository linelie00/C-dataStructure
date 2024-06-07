#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

// 함수 프로토타입 선언
void heapify_down(MinHeap* heap, int index);
void heapify_up(MinHeap* heap, int index);

// 힙 초기화
void init(MinHeap* heap) {
    heap->size = 0;
}

// 힙의 최소값 삭제 함수
void delete_min(MinHeap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        return;
    }
    if (heap->size == 1) {
        heap->size--;
        return;
    }
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    heapify_down(heap, 0);
}

// 임의의 요소 삭제 함수
void delete_element(MinHeap* heap, int index) {
    if (index >= heap->size) {
        printf("Index out of range\n");
        return;
    }
    heap->data[index] = heap->data[heap->size - 1];
    heap->size--;
    if (index == 0 || heap->data[index] > heap->data[(index - 1) / 2]) {
        heapify_down(heap, index);
    } else {
        heapify_up(heap, index);
    }
}

// 힙 위로 힙 정렬
void heapify_up(MinHeap* heap, int index) {
    while (index != 0 && heap->data[(index - 1) / 2] > heap->data[index]) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[(index - 1) / 2];
        heap->data[(index - 1) / 2] = temp;
        index = (index - 1) / 2;
    }
}

// 힙 아래로 힙 정렬
void heapify_down(MinHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap->size && heap->data[left] < heap->data[smallest]) {
        smallest = left;
    }
    if (right < heap->size && heap->data[right] < heap->data[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        int temp = heap->data[index];
        heap->data[index] = heap->data[smallest];
        heap->data[smallest] = temp;
        heapify_down(heap, smallest);
    }
}

// 힙에 요소 삽입
void insert(MinHeap* heap, int value) {
    if (heap->size >= MAX_SIZE) {
        printf("Heap is full\n");
        return;
    }
    heap->data[heap->size] = value;
    heap->size++;
    heapify_up(heap, heap->size - 1);
}

// 힙 출력
void print_heap(MinHeap* heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main() {
    MinHeap heap;
    init(&heap);

    insert(&heap, 20);
    insert(&heap, 12);
    insert(&heap, 3);
    insert(&heap, 2);
    insert(&heap, 5);
    insert(&heap, 16);

    printf("Initial heap: ");
    print_heap(&heap);

    // 임의의 요소 삭제 (예: 인덱스 3의 요소 삭제)
    delete_element(&heap, 3);
    printf("Heap after deleting element at index 3: ");
    print_heap(&heap);

    return 0;
}
