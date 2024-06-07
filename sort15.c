#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 노드 생성 함수
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 리스트에 노드 추가 함수 (헤드에 추가)
void push(Node** headRef, int data) {
    Node* newNode = createNode(data);
    newNode->next = *headRef;
    *headRef = newNode;
}

// 주어진 값으로 연결 리스트 출력
void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// 주어진 값을 오름차순으로 정렬된 위치에 삽입하는 함수
void sortedInsert(Node** headRef, Node* newNode) {
    Node* current;
    // 특수 경우: 헤드가 NULL이거나 헤드의 데이터가 새 노드의 데이터보다 클 때
    if (*headRef == NULL || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        // 적절한 위치를 찾기 위해 리스트를 순회
        current = *headRef;
        while (current->next != NULL && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 삽입 정렬 함수
void insertionSort(Node** headRef) {
    // 정렬된 리스트의 헤드 포인터
    Node* sorted = NULL;
    // 원래 리스트의 현재 노드
    Node* current = *headRef;
    // 리스트를 순회하며 각 노드를 정렬된 리스트에 삽입
    while (current != NULL) {
        // 다음 노드를 저장
        Node* next = current->next;
        // 현재 노드를 정렬된 리스트에 삽입
        sortedInsert(&sorted, current);
        // 다음 노드로 이동
        current = next;
    }
    // 헤드를 정렬된 리스트로 변경
    *headRef = sorted;
}

// 메인 함수
int main() {
    Node* head = NULL;

    // 테스트 데이터 추가
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    printf("정렬 전 리스트:\n");
    printList(head);

    insertionSort(&head);

    printf("정렬 후 리스트:\n");
    printList(head);

    return 0;
}
