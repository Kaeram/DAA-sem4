#include <stdio.h>
#include <limits.h>

#define MAX 20  // Max number of cities

int cost[MAX][MAX];
int n;

// Recursive function to find minimum cost
int totalCost(int mask, int pos) {
    // Base case: all cities visited
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    int ans = INT_MAX;

    // Try to go to an unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = cost[pos][city] + totalCost(mask | (1 << city), city);
            if (newAns < ans)
                ans = newAns;
        }
    }

    return ans;
}

// TSP function
int tsp() {
    return totalCost(1, 0); // Start at city 0, mask = 1 (only city 0 visited)
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int result = tsp();
    printf("The minimum cost to visit all cities: %d\n", result);

    return 0;
}
