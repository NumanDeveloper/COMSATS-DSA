#include<stdio.h>

void Max(int arr[], int i, int n)
{
    int l = 2*i + 1, r = 2*i + 2, largest = i, temp;
    
	if (l < n && arr[l] > arr[i])
        largest = l;
    
	if (r < n && arr[r] > arr[largest])
        largest = r;
    
	if (largest != i)
    {
        temp = arr[i];
		arr[i] = arr[largest];
        arr[largest] = temp;
		
		Max(arr, largest, n);
    }
}
    
int main()
{
	int arr1[5] = {1,2,3,4,5}, i, n=5;
	
	printf("Min Heap Array: ");
	for(i=0; i<5; i++)
	printf("\n%d", arr1[i]);
	
	for (int i = (n-2)/2; i >= 0; --i)
        Max(arr1, i, n);
	
	printf("\n\nAfter Converting to max heap: ");
	for(i=0; i<5; i++)
	printf("\n%d", arr1[i]);
	
	return 0;
}
