// Divide and conquer
// Recursive
// Not stable (not suitable for all data types for example if we want to solve a array which contains a pair of integers)

//  Time complexity:
//   O(n ( log n ) ) average case
//   O(n^2) worst case (can be avoided)

#include <stdio.h>

void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int Partition(int *A, int start, int end)
{
    int pivot = A[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            swap(&A[i], &A[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&A[partitionIndex], &A[end]);
    return partitionIndex;
}

void QuickSort(int *A, int start, int end)
{
    if (start < end)
    {
        int paritionIndex = Partition(A, start, end);
        QuickSort(A, start, paritionIndex - 1);
        QuickSort(A, paritionIndex + 1, end);
    }
}
int main()
{
    int n;
    printf("Enter the size of your array\n");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements of your array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    QuickSort(A, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}