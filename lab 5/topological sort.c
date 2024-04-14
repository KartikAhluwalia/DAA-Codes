#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjacencyList;
    int* visited;
};

struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->adjacencyList = (struct Node**)malloc(numVertices * sizeof(struct Node*));
    graph->visited = (int*)malloc(numVertices * sizeof(int));

    for (int i = 0; i < numVertices; i++) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void DFS(struct Graph* graph, int vertex, int* stack) {
    struct Node* temp = graph->adjacencyList[vertex];
    graph->visited[vertex] = 1;

    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex]) {
            DFS(graph, adjVertex, stack);
        }
        temp = temp->next;
    }

    // Push the current vertex to the stack after all its adjacent vertices are visited
    *stack = vertex;
    stack++;
}

void topologicalSortDFS(struct Graph* graph) {
    int* stack = (int*)malloc(graph->numVertices * sizeof(int));
    int* tempStack = stack;

    for (int i = 0; i < graph->numVertices; i++) {
        if (!graph->visited[i]) {
            DFS(graph, i, &tempStack);
        }
    }

    printf("Topological Sort using Depth-First Search:\n");
    while (tempStack != stack) {
        printf("%d ", *tempStack);
        tempStack--;
    }
    printf("\n");
    free(stack);
}

void topologicalSortSourceRemoval(struct Graph* graph) {
    int* indegree = (int*)calloc(graph->numVertices, sizeof(int));
    int* topoSort = (int*)malloc(graph->numVertices * sizeof(int));

    // Calculate indegree of each vertex
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjacencyList[i];
        while (temp != NULL) {
            indegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Source Removal algorithm
    int topoIndex = 0;
    for (int i = 0; i < graph->numVertices; i++) {
        int j;
        for (j = 0; j < graph->numVertices; j++) {
            if (indegree[j] == 0) {
                topoSort[topoIndex++] = j;
                indegree[j] = -1; // Mark the vertex as visited
                struct Node* temp = graph->adjacencyList[j];
                while (temp != NULL) {
                    indegree[temp->vertex]--;
                    temp = temp->next;
                }
                break;
            }
        }
        if (j == graph->numVertices) {
            printf("The graph is not a DAG (Directed Acyclic Graph).\n");
            free(indegree);
            free(topoSort);
            return;
        }
    }

    printf("Topological Sort using Source Removal:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", topoSort[i]);
    }
    printf("\n");

    free(indegree);
    free(topoSort);
}

int main() {
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    printf("Graph:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjacencyList[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    topologicalSortDFS(graph);
    topologicalSortSourceRemoval(graph);

    return 0;
}

