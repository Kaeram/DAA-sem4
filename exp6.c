#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int minDistance(int dist[], int visited[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void dijkstra(int** graph, int V, int src) {
    int dist[V];
    int visited[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nVertex \t Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    // Dynamically allocate memory for the graph
    int** graph = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++)
        graph[i] = (int*)malloc(V * sizeof(int));

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int src;
    printf("Enter the source vertex (0 to %d): ", V-1);
    scanf("%d", &src);

    dijkstra(graph, V, src);

    // Free memory
    for (int i = 0; i < V; i++)
        free(graph[i]);
    free(graph);

    return 0;
}
