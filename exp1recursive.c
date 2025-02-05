#include <stdio.h>
 int count =0;
// Recursive implementation of the binary search algorithm.
int binarySearch(int arr[], int low, int high, int number)
{    count++;
    if (low > high)
    {
    return -1;
    }
 
    // Discovers the mid-point in the search space and compares it to the target
    int mid = (low + high)/2;  
 
    // Base condition (target value is found)
    if (number == arr[mid])
    {
    return mid;
    }
 
    // Remove all elements from the right search space, including the middle element.
    else if (number < arr[mid])
    {
    return binarySearch(arr, low, mid - 1, number);
    }
 
    // Remove all elements from the left search space, including the middle element.
    else
    {
    return binarySearch(arr, mid + 1, high, number);
    }
}
 
int main(void)
{
int number;
int size; //array size
printf("Enter the value of arr size ");
scanf("%d",&size); // Input array size
int arr [size];
for(int i=0;i<size;i++)
{
printf("Enter array value\t");
scanf("%d",&arr[i]); // Input array value
}
printf("Enter the target value: ");
scanf("%d", &number);

int n = sizeof(arr)/sizeof(arr[0]);

int low = 0, high = n - 1;
int index = binarySearch(arr, low, high, number);
if (index != -1)
{
printf("Element found at index %d", index);
}
else
{
printf("Element not found in the array");
}
printf("total iterations %d",count);
return 0;
}