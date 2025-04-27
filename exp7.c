#include <stdio.h>
#include <stdlib.h>

#define INF 100000000

typedef struct {
    int u, v, wt;
} Edge;

int* bellmanFord(int V, Edge edges[], int E, int src) {
    int* dist = (int*)malloc(V * sizeof(int));
    
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int wt = edges[j].wt;

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                if (i == V - 1) {
                    free(dist);
                    return NULL; // Negative weight cycle detected
                }
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge* edges = (Edge*)malloc(E * sizeof(Edge));

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].wt);
    }

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int* ans = bellmanFord(V, edges, E, src);

    if (ans == NULL) {
        printf("-1\n"); // Negative weight cycle detected
    } else {
        printf("Shortest distances from source %d:\n", src);
        for (int i = 0; i < V; i++)
            printf("Vertex %d: %d\n", i, ans[i]);
        free(ans);
    }

    free(edges);
    return 0;
}
