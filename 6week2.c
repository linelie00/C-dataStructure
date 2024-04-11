#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void print_list(ListNode* head) {
    ListNode* p;

    if(head == NULL) return;
    p = head->link;
    for(int i=0; i<10;i++){
        printf("Current turn=%s\n", p->data);
        p = p->link;
    }
}

ListNode* insert_first(ListNode* head, element data) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    strcpy(node->data, data);
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

int main(void) {
    ListNode* head = NULL;
    
    head = insert_first(head, "PARK");
    head = insert_first(head, "CHOI");
    head = insert_first(head, "LEE");
    head = insert_first(head, "JUNG");
    head = insert_first(head, "KIM");
    
    print_list(head);
}