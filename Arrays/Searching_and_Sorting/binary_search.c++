// Binary Search in C++

#include <iostream>
using namespace std;

void print_array(int* arr, int s){
    cout<<"Elements of array are:\n";
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}
int binarySearch(int array[], int x, int low, int high)
{
    // Repeat until the pointers low and high meet each other
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (array[mid] == x)
            return mid;

        else if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    // CAUTION: Array must be sorted in order to use binary search 
    int x, array[] = {3, 4, 5, 6, 7, 8, 9};
    int s = sizeof(array) / sizeof(int);
    print_array(array, s);

    cout<<"Enter element to find: ";
    cin>>x;

    int result = binarySearch(array, x, 0, s - 1);
    (result == -1) ? cout<<"Not found !!" : cout<<"Element is found at index "<< result;

    return 0;
}