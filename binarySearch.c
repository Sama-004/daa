#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    printf("Enter the size of your array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in the sorted array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target element you want to search\n");
    int target;
    scanf("%d", &target);
    int result = binarySearch(arr, n, target);
    if (result != -1)
    {
        printf("Elements found at the index %d \n", result);
    }
    else
    {
        printf("Element not found in the array\n");
    }
    return 0;
}
