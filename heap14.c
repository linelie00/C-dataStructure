#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} PriorityQueue;

// 초기화 함수
void init(PriorityQueue *pq) {
    pq->size = 0;
}

// 우선순위 큐가 비어 있는지 확인하는 함수
int is_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

// 삽입 함수
void insert(PriorityQueue *pq, int value) {
    if (pq->size >= MAX_SIZE) {
        printf("Priority queue is full\n");
        return;
    }
    pq->data[pq->size] = value;
    pq->size++;
}

// 최솟값을 찾는 함수
int find_min(PriorityQueue *pq) {
    if (is_empty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    int min = pq->data[0];
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] < min) {
            min = pq->data[i];
        }
    }
    return min;
}

// 삭제 함수 (최솟값을 삭제)
int delete_min(PriorityQueue *pq) {
    if (is_empty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    int min_index = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->data[i] < pq->data[min_index]) {
            min_index = i;
        }
    }
    int min_value = pq->data[min_index];
    pq->data[min_index] = pq->data[pq->size - 1];
    pq->size--;
    return min_value;
}

// 메인 함수
int main() {
    PriorityQueue pq;
    init(&pq);

    char command;
    int value;

    while (1) {
        printf("삽입(i), 삭제(d), 종료(q): ");
        scanf(" %c", &command);

        if (command == 'i') {
            printf("값을 입력하세요: ");
            scanf("%d", &value);
            insert(&pq, value);
        } else if (command == 'd') {
            int min_value = delete_min(&pq);
            if (min_value != -1) {
                printf("제일 우선 순위가 높은 값은 %d\n", min_value);
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("잘못된 명령어입니다.\n");
        }
    }

    return 0;
}
