#include <stdio.h>
#include <limits.h>

// Function to find the min and max values using divide and conquer
void minmax(int arr[], int low, int high, int *min, int *max)
{
    if (low == high)
    { // Only one element in array
        *min = arr[low];
        *max = arr[low];
    }
    else if (high == low + 1)
    { // Only two elements in array
        if (arr[low] < arr[high])
        {
            *min = arr[low];
            *max = arr[high];
        }
        else
        {
            *min = arr[high];
            *max = arr[low];
        }
    }
    else
    {
        int mid = (low + high) / 2;
        int min1, max1, min2, max2;

        minmax(arr, low, mid, &min1, &max1);
        minmax(arr, mid + 1, high, &min2, &max2);

        // Combine results
        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int n;
    printf("Enter the size of the array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = INT_MAX, max = INT_MIN;
    minmax(arr, 0, n - 1, &min, &max);
    printf("%d is the minima and %d is the maxima \n", min, max);

    return 0;
}
