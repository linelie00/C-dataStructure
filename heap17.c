#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

// 우선순위 큐 구조체 정의
typedef struct PriorityQueue {
    Node *nodes[100];
    int size;
} PriorityQueue;

// 노드 생성 함수
Node* create_node(char character, int frequency) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->character = character;
    new_node->frequency = frequency;
    new_node->left = new_node->right = NULL;
    return new_node;
}

// 우선순위 큐 초기화 함수
void init_priority_queue(PriorityQueue *pq) {
    pq->size = 0;
}

// 우선순위 큐가 비어있는지 확인하는 함수
int is_empty(PriorityQueue *pq) {
    return pq->size == 0;
}

// 우선순위 큐에 노드를 삽입하는 함수
void insert_priority_queue(PriorityQueue *pq, Node *node) {
    int i = pq->size++;
    while (i && node->frequency < pq->nodes[(i - 1) / 2]->frequency) {
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    pq->nodes[i] = node;
}

// 우선순위 큐에서 최소 빈도수를 가진 노드를 제거하는 함수
Node* extract_min(PriorityQueue *pq) {
    Node *min_node = pq->nodes[0];
    Node *last_node = pq->nodes[--pq->size];
    int i = 0, child;
    while ((child = 2 * i + 1) < pq->size) {
        if (child + 1 < pq->size && pq->nodes[child + 1]->frequency < pq->nodes[child]->frequency)
            child++;
        if (last_node->frequency <= pq->nodes[child]->frequency)
            break;
        pq->nodes[i] = pq->nodes[child];
        i = child;
    }
    pq->nodes[i] = last_node;
    return min_node;
}

// 호프만 트리를 생성하는 함수
Node* build_huffman_tree(char characters[], int frequencies[], int size) {
    PriorityQueue pq;
    init_priority_queue(&pq);

    for (int i = 0; i < size; ++i) {
        insert_priority_queue(&pq, create_node(characters[i], frequencies[i]));
    }

    while (pq.size > 1) {
        Node *left = extract_min(&pq);
        Node *right = extract_min(&pq);
        Node *combined = create_node('$', left->frequency + right->frequency);
        combined->left = left;
        combined->right = right;
        insert_priority_queue(&pq, combined);
    }

    return extract_min(&pq);
}

// 호프만 코드 출력을 위한 헬퍼 함수
void print_codes(Node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// 트리 구조 출력을 위한 함수 (레벨 순회)
void print_tree_level_order(Node *root) {
    if (!root) return;

    // 큐 구현
    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node *current = queue[front++];

        if (current->character != '$') {
            printf("%c(%d) ", current->character, current->frequency);
        } else {
            printf("%d ", current->frequency);
        }

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("\n");
}

// 호프만 코드를 출력하는 함수
void huffman_codes(char characters[], int frequencies[], int size) {
    Node *root = build_huffman_tree(characters, frequencies, size);
    int arr[100], top = 0;

    printf("Huffman Codes:\n");
    print_codes(root, arr, top);

    printf("\nHuffman Tree (Level Order):\n");
    print_tree_level_order(root);
}

int main() {
    char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int frequencies[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int size = sizeof(characters) / sizeof(characters[0]);

    huffman_codes(characters, frequencies, size);

    return 0;
}
