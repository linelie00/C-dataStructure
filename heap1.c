#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char task[100];
    int priority;
} Task;

typedef struct {
    Task tasks[MAX];
    int size;
} MaxHeap;

void swap(Task *a, Task *b) {
    Task temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MaxHeap *heap, char task[], int priority) {
    if (heap->size >= MAX) {
        printf("Heap is full\n");
        return;
    }
    
    Task newTask;
    strcpy(newTask.task, task);
    newTask.priority = priority;
    
    heap->tasks[heap->size] = newTask;
    int i = heap->size;
    heap->size++;
    
    while (i != 0 && heap->tasks[(i - 1) / 2].priority < heap->tasks[i].priority) {
        swap(&heap->tasks[i], &heap->tasks[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Task extractMax(MaxHeap *heap) {
    if (heap->size <= 0) {
        printf("Heap is empty\n");
        Task emptyTask = {"", -1};
        return emptyTask;
    }
    
    if (heap->size == 1) {
        heap->size--;
        return heap->tasks[0];
    }
    
    Task root = heap->tasks[0];
    heap->tasks[0] = heap->tasks[heap->size - 1];
    heap->size--;
    
    int i = 0;
    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        
        if (left < heap->size && heap->tasks[left].priority > heap->tasks[largest].priority) {
            largest = left;
        }
        
        if (right < heap->size && heap->tasks[right].priority > heap->tasks[largest].priority) {
            largest = right;
        }
        
        if (largest != i) {
            swap(&heap->tasks[i], &heap->tasks[largest]);
            i = largest;
        } else {
            break;
        }
    }
    
    return root;
}

int main() {
    MaxHeap heap;
    heap.size = 0;
    char option;
    char task[100];
    int priority;
    
    while (1) {
        printf("삽입(i), 삭제(d): ");
        scanf(" %c", &option);
        
        if (option == 'i') {
            printf("할일: ");
            scanf(" %s", task);
            printf("우선순위: ");
            scanf("%d", &priority);
            insert(&heap, task, priority);
        } else if (option == 'd') {
            Task maxTask = extractMax(&heap);
            if (maxTask.priority != -1) {
                printf("제일 우선 순위가 높은 일은 \"%s\"\n", maxTask.task);
            }
        } else {
            printf("Invalid option\n");
        }
    }
    
    return 0;
}
