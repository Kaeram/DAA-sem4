#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// A utility function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed MST
void printMST(int parent[], int **graph, int V)
{
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[parent[i]][i]);
}

// Function to construct and print MST
void primMST(int **graph, int V)
{
    int *parent = (int *)malloc(V * sizeof(int));
    int *key = (int *)malloc(V * sizeof(int));
    bool *mstSet = (bool *)malloc(V * sizeof(bool));

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1; // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph, V);

    free(parent);
    free(key);
    free(mstSet);
}

// Driver's code
int main()
{
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Dynamic memory allocation for adjacency matrix
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        graph[i] = (int *)malloc(V * sizeof(int));

    printf("Enter adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Print the solution
    primMST(graph, V);

    // Free allocated memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
