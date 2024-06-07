#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// AVL 트리 노드 구조체
typedef struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// 새로운 노드를 생성하는 함수
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
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
AVLNode* insert(AVLNode* node, int key) {
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

// AVL 트리의 높이를 반환하는 함수
int getTreeHeight(AVLNode* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// AVL 트리를 삭제하는 함수
void freeTree(AVLNode* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

// 난수 생성기 함수
void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// 실험 함수
void runExperiment(int n, int iterations) {
    int totalHeight = 0;

    for (int i = 0; i < iterations; i++) {
        AVLNode* root = NULL;
        int* numbers = (int*)malloc(n * sizeof(int));
        generateRandomNumbers(numbers, n);

        for (int j = 0; j < n; j++) {
            root = insert(root, numbers[j]);
        }

        totalHeight += getTreeHeight(root);
        freeTree(root);
        free(numbers);
    }

    double averageHeight = (double)totalHeight / iterations;
    double theoreticalHeight = 2 * log2(n + 1);

    printf("n = %d\n", n);
    printf("Average Height: %f\n", averageHeight);
    printf("Theoretical Height: %f\n", theoreticalHeight);
    printf("\n");
}

int main() {
    srand(time(0));

    int iterations = 10;

    runExperiment(100, iterations);
    runExperiment(500, iterations);
    runExperiment(1000, iterations);
    runExperiment(10000, iterations);
    runExperiment(50000, iterations);

    return 0;
}
