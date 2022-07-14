// Online C compiler to run C program online
#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];// for storing sorted array
    i = low;// for start index of 1st sorted array
    j = mid + 1;// for start index of 2nd sorted array
    k = low;// for start index of 3rd array that will store whole sorted array

    while (i <= mid && j <= high)
    {// compare elements of two sorted arrays
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
     // copy remaining elements to new sorted array if any left in sub-sorted arrays
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    // copy new sorted array to original array
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}
// merge_sort will keep on dividing the array until single elements remains that can't be furthur sub-divided
void merge_sort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        // applying merge_sort on left half
        merge_sort(A, low, mid);
        // applying merge_sort on right half
        merge_sort(A, mid+1, high);
        // when array has been divided into single elements completely, start merging the elements
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = sizeof(A)/sizeof(int);
    printArray(A, n);
    merge_sort(A, 0, 6);
    printArray(A, n);
    return 0;
}
