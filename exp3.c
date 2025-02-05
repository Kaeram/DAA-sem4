#include <stdio.h>
#include <stdlib.h>

int a[10][10], visited[10], n, cost = 0;

// Function prototype for least
int least(int c);

void get() {
    int i, j;
    printf("Enter No. of Cities: ");
    scanf("%d", &n);
    printf("\nEnter Cost Matrix: \n");
    for (i = 0; i < n; i++) {
        printf("\nEnter Elements of Row # : %d\n", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
        visited[i] = 0; // Mark all cities as unvisited
    }
    printf("\n\nThe cost list is:\n\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n; j++) {
            printf("\t%d", a[i][j]);
        }
    }
}

void mincost(int city) {
    int ncity;
    visited[city] = 1; // Mark the current city as visited
    printf("%d -> ", city + 1); // Print the current city
    ncity = least(city); // Find the next city with the least cost
    if (ncity == 999) { // If no unvisited cities are left
        ncity = 0; // Return to the starting city
        printf("%d", ncity + 1); // Print the starting city
        cost += a[city][ncity]; // Add the cost to return to the starting city
        return;
    }
    cost += a[city][ncity]; // Add the cost to travel to the next city
    mincost(ncity); // Recursively visit the next city
}

int least(int c) {
    int i, nc = 999;
    int min = 999, kmin;
    for (i = 0; i < n; i++) {
        if ((a[c][i] != 0) && (visited[i] == 0)) { // Check for unvisited cities
            if (a[c][i] < min) { // Find the city with the least cost
                min = a[c][i];
                kmin = a[c][i];
                nc = i; // Update the next city
            }
        }
    }
    return nc; // Return the next city
}

void put() {
    printf("\n\nMinimum cost: %d\n", cost);
}

int main() {
    get(); // Get the input from the user
    printf("\n\nThe Path is:\n\n");
    mincost(0); // Start the tour from the first city
    put(); // Print the minimum cost
    return 0; // Return success
}