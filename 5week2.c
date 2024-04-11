#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;

// 오류 처리 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert(int n) {
    // 첫 번째 노드 생성 및 연결
    head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) {
        error("메모리 할당 오류\n");
    }
    head->data = 1;
    head->link = NULL;
    tail = head;

    // 나머지 노드들 생성 및 연결
    for (int i = 2; i <= n; i++) {
        ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
        if (new_node == NULL) {
            error("메모리 할당 오류\n");
        }
        new_node->data = i;
        new_node->link = NULL;
        tail->link = new_node;
        tail = new_node;
    }

    // 마지막 노드와 첫 번째 노드를 연결하여 원형으로 만듦
    tail->link = head;

    return head;
}

void deleteNode(ListNode *prev, ListNode *cur, int *n) {
    prev->link = cur->link;
    if (*n == 1)
        printf("%d", cur->data);
    else
        printf("%d, ", cur->data);
    free(cur);
}

void delete(int n, int k) {
    if (head == NULL) {
        error("리스트가 비어있습니다.\n");
        return;
    }

    ListNode *prev;
    ListNode *cur;

    while (n > 0) {
        // k번째 노드까지 이동
        prev = NULL;
        cur = head;
        for (int i = 0; i < k - 1; i++) {
            prev = cur;
            cur = cur->link;
        }

        // k번째 노드 삭제
        deleteNode(prev, cur, &n);
        head = prev->link;
        n--;

        if (n == 0)
            break;

        prev->link = head;
    }
}

// 테스트 프로그램
int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    insert(n);
    delete(n, k);
    return 0;
}