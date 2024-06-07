#include <stdio.h>
#include <stdlib.h>

// 이진 탐색 트리 노드 구조체 정의
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// 새로운 노드를 생성하는 함수
BSTNode* createNode(int key) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 이진 탐색 트리에 노드를 삽입하는 함수
BSTNode* insert(BSTNode* node, int key) {
    if (node == NULL) 
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

// 중위 순회를 사용하여 트리의 요소들을 오름차순으로 출력하는 함수
void inorderTraversal(BSTNode* root, int* arr, int* index) {
    if (root != NULL) {
        inorderTraversal(root->left, arr, index);
        arr[*index] = root->key;
        (*index)++;
        inorderTraversal(root->right, arr, index);
    }
}

// BST 기반의 정렬 함수
void bstSort(int* arr, int n) {
    BSTNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    int index = 0;
    inorderTraversal(root, arr, &index);
}

// 배열 출력 함수
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 메인 함수
int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bstSort(arr, n);

    printf("Sorted array using BST sort:\n");
    printArray(arr, n);

    return 0;
}
