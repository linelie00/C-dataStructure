#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int numVertices;
    Node** adjLists;
} Graph;

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
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bridgeUtil(Graph* graph, int u, bool visited[], int disc[], int low[], int parent[], int* time) {
    static const int NIL = -1;

    visited[u] = true;
    disc[u] = low[u] = ++(*time);

    Node* adjNode = graph->adjLists[u];
    while (adjNode != NULL) {
        int v = adjNode->vertex;

        if (!visited[v]) {
            parent[v] = u;
            bridgeUtil(graph, v, visited, disc, low, parent, time);

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            if (low[v] > disc[u]) {
                printf("Bridge found between vertices %d and %d\n", u, v);
            }
        } else if (v != parent[u]) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }

        adjNode = adjNode->next;
    }
}

void findBridges(Graph* graph) {
    bool visited[MAX_VERTICES];
    int disc[MAX_VERTICES];
    int low[MAX_VERTICES];
    int parent[MAX_VERTICES];

    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = false;
        parent[i] = -1;
    }

    int time = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        if (!visited[i]) {
            bridgeUtil(graph, i, visited, disc, low, parent, &time);
        }
    }
}

int main() {
    int vertices = 5;
    Graph* graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    printf("Bridges in the graph:\n");
    findBridges(graph);

    return 0;
}
