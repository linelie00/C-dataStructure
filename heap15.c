#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
} Node;

// 우선순위 큐 구조체 정의
typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

// 우선순위 큐 초기화
void init(PriorityQueue* pq) {
    pq->head = NULL;
}

// 우선순위 큐가 비어 있는지 확인
bool is_empty(PriorityQueue* pq) {
    return pq->head == NULL;
}

// 노드를 생성
Node* create_node(int data, int priority) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

// 우선순위 큐에 삽입
void insert(PriorityQueue* pq, int data, int priority) {
    Node* new_node = create_node(data, priority);
    if (is_empty(pq) || pq->head->priority > priority) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        Node* current = pq->head;
        while (current->next != NULL && current->next->priority <= priority) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

// 우선순위 큐에서 최댓값 제거
int delete_max(PriorityQueue* pq) {
    if (is_empty(pq)) {
        printf("Priority queue is empty\n");
        return -1;
    }
    Node* temp = pq->head;
    pq->head = pq->head->next;
    int data = temp->data;
    free(temp);
    return data;
}

// 메인 함수
int main() {
    PriorityQueue pq;
    init(&pq);

    char command;
    int data, priority;

    while (1) {
        printf("삽입(i), 삭제(d), 종료(q): ");
        scanf(" %c", &command);

        if (command == 'i') {
            printf("값을 입력하세요: ");
            scanf("%d", &data);
            printf("우선순위를 입력하세요: ");
            scanf("%d", &priority);
            insert(&pq, data, priority);
        } else if (command == 'd') {
            int max_value = delete_max(&pq);
            if (max_value != -1) {
                printf("제일 우선 순위가 높은 값은 %d\n", max_value);
            }
        } else if (command == 'q') {
            break;
        } else {
            printf("잘못된 명령어입니다.\n");
        }
    }

    return 0;
}
