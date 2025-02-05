#include <stdio.h>
int count=0;

int binary(int a[], int low, int high, int x) {
    while (low <= high) {
        count++;
        int mid = low + (high - low) / 2;
        if (a[mid] == x) {
            return mid;
        }
        if (a[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter number of elements: \n");
    scanf("%d", &n);
   
    int a[n];
    printf("Enter numbers in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
   
    int x;
    printf("Enter the key you want to search for: \n");
    scanf("%d", &x);
    int result = binary(a, 0, n - 1, x);
   
    if (result == -1) {
        printf("Element is not present in the array.\n");
    } else {
        printf("Element %d is present at index %d.\n", x, result);
        printf("total iterations: %d",count);
    }
   
    return 0;
}

