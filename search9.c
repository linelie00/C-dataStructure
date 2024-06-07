#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVL 트리 노드 구조체 정의
typedef struct AVLNode {
    char key[4]; // 최대 3글자의 키를 저장할 수 있도록 변경
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// 새로운 노드를 생성하는 함수
AVLNode* createNode(char* key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    strcpy(node->key, key);
    node->left = NULL;
    node->right = NULL;
    node->height = 1; // 새로운 노드는 높이가 1
    return node;
}

// 노드의 높이를 반환하는 함수
int height(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// 최대값을 반환하는 함수
int max(int a, int b) {
    return (a > b) ? a : b;
}

// 오른쪽으로 회전하는 함수
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// 왼쪽으로 회전하는 함수
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// 노드의 균형 인수를 반환하는 함수
int getBalance(AVLNode* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

// AVL 트리에 노드를 삽입하는 함수
AVLNode* insert(AVLNode* node, char* key) {
    if (node == NULL)
        return createNode(key);

    if (strcmp(key, node->key) < 0)
        node->left = insert(node->left, key);
    else if (strcmp(key, node->key) > 0)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && strcmp(key, node->left->key) < 0)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && strcmp(key, node->right->key) > 0)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && strcmp(key, node->left->key) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && strcmp(key, node->right->key) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// 중위 순회를 사용하여 트리의 요소들을 출력하는 함수
void inorderTraversal(AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s ", root->key);
        inorderTraversal(root->right);
    }
}

// 트리의 구조를 출력하는 함수
void printTree(AVLNode* root, int space) {
    int COUNT = 5;
    if (root == NULL)
        return;

    space += COUNT;

    printTree(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%s\n", root->key);

    printTree(root->left, space);
}

int main() {
    AVLNode* root = NULL;
    char* keys[] = {"Dec", "Jan", "Apr", "Mar", "July", "Aug", "Oct", "Feb", "Sept", "Nov", "June", "May"};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        printf("Inserting: %s\n", keys[i]);
        root = insert(root, keys[i]);
        printTree(root, 0);
        printf("\n");
    }

    printf("Final AVL Tree (Inorder Traversal):\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
