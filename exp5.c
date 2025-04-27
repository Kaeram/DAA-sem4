#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    int i, w;
    // Using dynamic memory allocation for the 2D array
    int **K = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        K[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    // Build the K table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Store the result
    int result = K[n][W];

    // Backtrack to find which items are included
    int *selectedItems = (int *)malloc(n * sizeof(int));
    int count = 0;
    w = W;

    for (i = n; i > 0 && result > 0; i--) {
        // Check if the item was included
        if (result != K[i - 1][w]) {
            selectedItems[count++] = i - 1; // Store the index of the included item
            result -= val[i - 1];
            w -= wt[i - 1];
        }
    }

    // Print selected items
    printf("Selected items (0-indexed): ");
    for (i = count - 1; i >= 0; i--) {
        printf("%d ", selectedItems[i]);
    }
    printf("\n");

    // Free allocated memory
    for (i = 0; i <= n; i++) {
        free(K[i]);
    }
    free(K);
    free(selectedItems);

    return K[n][W];
}

int main() {
    int i, n, val[20], wt[20], W;

    printf("Enter number of items: ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 20) {
        printf("Invalid number of items.\n");
        return 1;
    }

    printf("Enter value and weight of items:\n");
    for (i = 0; i < n; ++i) {
        if (scanf("%d%d", &val[i], &wt[i]) != 2) {
            printf("Invalid input for value and weight.\n");
            return 1;
        }
    }

    printf("Enter size of knapsack: ");
    if (scanf("%d", &W) != 1 || W <= 0) {
        printf("Invalid size of knapsack.\n");
        return 1;
    }

    printf("Profit = %d\n", knapSack(W, wt, val, n));
    return 0;
}
