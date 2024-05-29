// Divide and conquer
// Time complexity: O (n log n)
#include <stdio.h>
#include <stdlib.h>

// This function merges the two divided arrays into a single array
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int l[n1], r[n2];
    for (i = 0; i < n1; i++)
        l[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        r[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            arr[k] = l[i];
            i++;
        }
        else
        {
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[] and R[], if there are any
    while (i < n1)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

// this function sorts the array
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2; // for overflow issue
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {12, 133, 11, 15, 19, 20};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("The given array is\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mergeSort(arr, 0, arr_size - 1);
    printf("The sorted array is \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}