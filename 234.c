#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int keys[3];
    struct Node* children[4];
    int numKeys;
    int isLeaf;
} Node;

Node* createNode(int key, int isLeaf) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->numKeys = 1;
    newNode->isLeaf = isLeaf;
    for (int i = 0; i < 4; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

void splitChild(Node* parent, int i) {
    Node* y = parent->children[i];
    Node* z = createNode(y->keys[2], y->isLeaf);
    z->numKeys = 1;

    if (!y->isLeaf) {
        for (int j = 0; j < 2; j++) {
            z->children[j] = y->children[j + 2];
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
        if (node->children[i]->numKeys == 3) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

Node* insert(Node* root, int key) {
    if (root->numKeys == 3) {
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

    printf("2-3-4 트리:\n");
    printTree(root, 0);

    return 0;
}
