#include <stdio.h>

void minmax(int arr[], int n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= *max)
        {
            *max = arr[i];
        }
        else
        {
            if (arr[i] <= *min)
            {
                *min = arr[i];
            }
        }
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
    int min, max;
    minmax(arr, n, &min, &max);
    printf("%d is the minima and %d is the maxima\n", min, max);
}
// Time complexity:-

// O(n - 1) in best case
// O(2(n-1)) in the worst case
