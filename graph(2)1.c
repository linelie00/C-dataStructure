#include <stdio.h>
#include <stdlib.h>

// 그래프 구조체 정의
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int numVertices;
    Node** adjLists;
    int* visited;
} Graph;

// 스택 구조체 정의
typedef struct Stack {
    int* array;
    int top;
    int capacity;
} Stack;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (!isStackEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return -1;
}

void topologicalSortUtil(Graph* graph, int v, Stack* stack) {
    graph->visited[v] = 1;

    Node* temp = graph->adjLists[v];
    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!graph->visited[connectedVertex]) {
            topologicalSortUtil(graph, connectedVertex, stack);
        }
        temp = temp->next;
    }
    push(stack, v);
}

void topologicalSort(Graph* graph) {
    Stack* stack = createStack(graph->numVertices);

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            topologicalSortUtil(graph, i, stack);
        }
    }

    while (!isStackEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("위상 정렬: ");
    topologicalSort(graph);

    return 0;
}
