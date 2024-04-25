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

void preorder(TreeNode* ptr) {
    if(ptr) {
        printf("%d ", ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(TreeNode* ptr) {
    if(ptr) {
        inorder(ptr->left);
        printf("%d ", ptr->data);
        inorder(ptr->right);
    
    }
}

void postorder(TreeNode* ptr) {
    if(ptr) {
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d ", ptr->data);
    }
}

int main() {

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}
