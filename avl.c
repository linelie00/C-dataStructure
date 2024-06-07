#include <stdio.h>
#include <stdlib.h>

// AVL 트리 노드 구조체 정의
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// 노드의 높이를 반환하는 함수
int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// 새로운 노드를 생성하는 함수
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// 최대값을 반환하는 함수
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 오른쪽으로 회전하는 함수
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// 왼쪽으로 회전하는 함수
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// 노드의 균형 인수를 얻는 함수
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// AVL 트리에 노드를 삽입하는 함수
Node* insert(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 전위 순회를 수행하는 함수
void preOrder(Node* root) {
    if (root != NULL) {
        printf("[%d] ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 29);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("전위 순회 결과: \n");
    preOrder(root);

    return 0;
}
