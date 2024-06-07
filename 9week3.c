#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNode {
    int weight;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
    TreeNode* ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// Function prototypes
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));

};
void init(HeapType* h){
    h->heap_size = 0;
};
void insert_min_heap(HeapType* h, element item) {
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key < h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = item;
};
element delete_min_heap(HeapType* h) {
    int parent, child;
    element item, temp;
    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];
    parent = 1;
    child = 2;
    while (child <= h->heap_size) {
        if ((child < h->heap_size) &&
        (h->heap[child].key) > h->heap[child + 1].key)
            child++;
        if (temp.key <= h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
};
TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;
    node->weight = left->weight + right->weight;
    return node;
};
void destroy_tree(TreeNode* root) {
    if (root == NULL) return;
    destroy_tree(root->left);
    destroy_tree(root->right);
    free(root);
};
int is_leaf(TreeNode* root) {
    return !(root->left) && !(root->right);
};
void print_codes(TreeNode* node, int codes[], int top) {
    if (node->left) {
        codes[top] = 0;
        print_codes(node->left, codes, top + 1);
    }
    if (node->right) {
        codes[top] = 1;
        print_codes(node->right, codes, top + 1);
    }
    if (is_leaf(node)) {
        printf("%c: ", node->ch);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
};
void huffman(char data[], int freq[], int size) {
    int i;
    TreeNode* node, *x, *y;
    HeapType* heap;
    element e, e1, e2;
    int codes[100];
    int top = 0;

    heap = create();
    init(heap);
    for (i = 0; i < size; i++) {
        node = (TreeNode*)malloc(sizeof(TreeNode));
        node->ch = data[i];
        node->weight = freq[i];
        node->left = node->right = NULL;
        e.ptree = node;
        e.ch = data[i];
        e.key = freq[i];
        insert_min_heap(heap, e);
    }
    for (i = 1; i < size; i++) {
        e1 = delete_min_heap(heap);
        e2 = delete_min_heap(heap);
        x = e1.ptree;
        y = e2.ptree;
        node = make_tree(x, y);
        e.ptree = node;
        e.key = x->weight + y->weight;
        insert_min_heap(heap, e);
    }
    e = delete_min_heap(heap);
    print_codes(e.ptree, codes, top);
    destroy_tree(e.ptree);
    free(heap);

};

int main() {
    char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq1[] = {5, 9, 12, 13, 16, 45};

    char arr2[] = {'g', 'h', 'i', 'j'};
    int freq2[] = {3, 7, 10, 14};

    char arr3[] = {'k', 'l', 'm', 'n', 'o'};
    int freq3[] = {1, 4, 5, 6, 8};

    printf("Test Case 1:\n");
    huffman(arr1, freq1, sizeof(arr1) / sizeof(arr1[0]));
    printf("\nTest Case 2:\n");
    huffman(arr2, freq2, sizeof(arr2) / sizeof(arr2[0]));
    printf("\nTest Case 3:\n");
    huffman(arr3, freq3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}