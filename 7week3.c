#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char value;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *createNode(char value) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preorder(TreeNode *root) {
    if (root == NULL)
        return;

    printf("%c", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%c", root->value);
    inorder(root->right);
}

void postorder(TreeNode *root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%c", root->value);
}

int main() {
    int N;
    scanf("%d", &N);

    TreeNode *nodes[26] = {NULL, };

    for (int i = 0; i < N; i++) {
        char parentValue, leftValue, rightValue;
        scanf(" %c %c %c", &parentValue, &leftValue, &rightValue);

        if (nodes[parentValue - 'A'] == NULL) {
            nodes[parentValue - 'A'] = createNode(parentValue);
        }

        if (leftValue != '.') {
            nodes[leftValue - 'A'] = createNode(leftValue);
            nodes[parentValue - 'A']->left = nodes[leftValue - 'A'];
        }

        if (rightValue != '.') {
            nodes[rightValue - 'A'] = createNode(rightValue);
            nodes[parentValue - 'A']->right = nodes[rightValue - 'A'];
        }
    }

    preorder(nodes['A' - 'A']);
    printf("\n");
    inorder(nodes['A' - 'A']);
    printf("\n");
    postorder(nodes['A' - 'A']);
    printf("\n");

    return 0;
}
