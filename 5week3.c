#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element num;
    int data;
    struct ListNode *prev;
    struct ListNode *next;
} ListNode;

ListNode *head = NULL;
ListNode *tail = NULL;

// 오류 처리 함수
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert(int n) {
    int data;
    // 첫 번째 노드 생성 및 연결
    head = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) {
        error("메모리 할당 오류\n");
    }
    scanf("%d", &data);
    head->data = data;
    head->num = 1;
    head->prev = NULL;
    tail = head;

    // 나머지 노드들 생성 및 연결
    for (int i = 2; i <= n; i++) {
        ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
        if (new_node == NULL) {
            error("메모리 할당 오류\n");
        }
        scanf("%d", &data);
        new_node->data = data;
        new_node->num = i;
        new_node->prev = tail;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }

    // 마지막 노드와 첫 번째 노드를 연결하여 양방향 연결리스트 완성
    head->prev = tail;
    tail->next = head;

    return head;
}

void deleteNode(ListNode *cur) {
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    printf("%d", cur->num);
    if (cur->next != head)
        printf(" ");
    free(cur);
}

void delete(int n) {
    if (head == NULL) {
        error("리스트가 비어있습니다.\n");
        return;
    }

    ListNode *cur = head;
    int data;
    int c = n;

    for(int j = 0; j<c; j++) {
        data = cur->data;
        deleteNode(cur);

        if (data > 0) {
            for (int i = 0; i < data; i++) {
                cur = cur->next;
            }
        } else {
            int count = n;
            while(n!=1) {
                if(count> -data)
                    break;
                else if(count== -data) {
                    count = n - data - 1;
                    break;
                }
                count *= n;
            }
            for (int i = 0; i < count + data; i++) {
                cur = cur->next;
            }
        }
        head = cur;
        n--;
    }
}


// 테스트 프로그램
int main(void) {
    int n;
    scanf("%d", &n);
    insert(n);
    delete(n);
    return 0;
}
