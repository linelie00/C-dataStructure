#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode A1 = {1,NULL,NULL};
TreeNode A2 = {4,&A1,NULL};
TreeNode A3 = {16,NULL,NULL};
TreeNode A4 = {25,NULL,NULL};
TreeNode A5 = {20,&A3,&A4};
TreeNode A6 = {15,&A2,&A5};
TreeNode *root = &A6;

void levelorder(TreeNode* ptr) {
    if(ptr) {
        TreeNode* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = ptr;
        while(front < rear) {
            TreeNode* current = queue[front++];
            printf("%d ", current->data);
            if(current->left) queue[rear++] = current->left;
            if(current->right) queue[rear++] = current->right;
        }
    }
}

int main() {

    levelorder(root);

    return 0;
}
