#include <stdio.h>
#include <stdlib.h>

// 2-3 트리 노드 구조체 정의
typedef struct Node {
    int keys[2];          // 최대 두 개의 키를 가질 수 있음
    struct Node* children[3]; // 최대 세 개의 자식을 가질 수 있음
    int numKeys;          // 현재 키의 수
    int isLeaf;           // 리프 노드인지 여부
} Node;

// 노드 생성 함수
Node* createNode(int key, int isLeaf) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->numKeys = 1;
    newNode->isLeaf = isLeaf;
    for (int i = 0; i < 3; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// 자식 노드를 분할하는 함수
void splitChild(Node* parent, int i) {
    Node* y = parent->children[i];
    Node* z = createNode(y->keys[1], y->isLeaf);
    z->numKeys = 1;

    if (!y->isLeaf) {
        for (int j = 0; j < 2; j++) {
            z->children[j] = y->children[j + 1];
        }
    }

    y->numKeys = 1;

    for (int j = parent->numKeys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }

    parent->children[i + 1] = z;

    for (int j = parent->numKeys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }

    parent->keys[i] = y->keys[1];
    parent->numKeys++;
}

// 비가득 노드에 키를 삽입하는 함수
void insertNonFull(Node* node, int key) {
    int i = node->numKeys - 1;

    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i] != NULL && node->children[i]->numKeys == 2) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// 2-3 트리에 키를 삽입하는 함수
Node* insert(Node* root, int key) {
    if (root->numKeys == 2) {
        Node* newRoot = createNode(0, 0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// 2-3 트리에서 키를 검색하는 함수
Node* search(Node* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }

    if (i < root->numKeys && key == root->keys[i]) {
        return root;
    }

    if (root->isLeaf) {
        return NULL;
    }

    return search(root->children[i], key);
}

// 트리를 전위 순회하며 출력하는 함수
void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    printf("Level %d: ", level);
    for (int i = 0; i < root->numKeys; i++) {
        printf("%d ", root->keys[i]);
    }
    printf("\n");

    for (int i = 0; i <= root->numKeys; i++) {
        printTree(root->children[i], level + 1);
    }
}

int main() {
    Node* root = createNode(30, 1);

    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 29);
    root = insert(root, 40);
    root = insert(root, 50);

    printf("2-3 트리:\n");
    printTree(root, 0);

    return 0;
}
