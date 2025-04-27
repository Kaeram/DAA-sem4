#include <stdio.h>
#include <stdlib.h>

// Comparator function to use in sorting
int comparator(const void *p1, const void *p2)
{
    int *a = (int *)p1;
    int *b = (int *)p2;
    return a[2] - b[2];
}

// Initialization of parent[] and rank[] arrays
void makeSet(int parent[], int rank[], int n)
{
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the parent of a node
int findParent(int parent[], int component)
{
    if (parent[component] == component)
        return component;
    return parent[component] = findParent(parent, parent[component]);
}

// Function to unite two sets
void unionSet(int u, int v, int parent[], int rank[])
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    }
    else if (rank[u] > rank[v]) {
        parent[v] = u;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to find the MST
int kruskalAlgo(int nVertices, int nEdges, int edge[][3])
{
    // First we sort the edge array in ascending order
    qsort(edge, nEdges, sizeof(edge[0]), comparator);

    int parent[nVertices];
    int rank[nVertices];

    makeSet(parent, rank, nVertices);

    int minCost = 0;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < nEdges; i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        int wt = edge[i][2];

        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);

        if (parentU != parentV) {
            unionSet(parentU, parentV, parent, rank);
            minCost += wt;
            printf("%d - %d : %d\n", u, v, wt);
        }
    }

    return minCost;
}

// Driver code
int main()
{
    int nVertices, nEdges;
    printf("Enter number of vertices: ");
    scanf("%d", &nVertices);
    printf("Enter number of edges: ");
    scanf("%d", &nEdges);

    int edge[nEdges][3];
    printf("Enter edges as (source destination weight):\n");
    for (int i = 0; i < nEdges; i++) {
        scanf("%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }

    int minCost = kruskalAlgo(nVertices, nEdges, edge);
    printf("Minimum cost of the MST = %d\n", minCost);

    return 0;
}
