#include <iostream>
using namespace std;

void printArray(int*, int);
void insertionSort(int*, int);

int main(){
    int arr[] = {2, 1 ,5, 22, 4};
    int s = sizeof(arr)/sizeof(int);

    printArray(arr, s);
    insertionSort(arr, s);

    return 0;
}
void printArray(int* arr, int s){
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}

void insertionSort(int* arr, int s){
    /**
     * Logic:
     * select a key value and assume first element to be pre-sorted
     * take j=i-1 and compare key with its left side elements
     * and shift A[j] to A[j+1] until j>=0
     * set A[j+1] = key
     */
    int key, j;
    // loop for passes. # of passes = n-1
    for (int i = 1; i < s; i++)
    {
        // assuming first value to be sorted
        key = arr[i]; // key is marker between sorted and unsorted array
        j = i-1; // j is the index of sorted array
        while (j >= 0 && key < arr[j])
        {
            arr[j+1] = arr[j]; // shift to right side
            j--;
        }
        arr[j+1] = key;
    }
    printArray(arr, s);
}