#include <iostream>
using namespace std;

void print_array(int*, int);
void insertion_sort(int*, int);

int main(){
    int arr[] = {2, 1 ,5, 22, 4};
    int s = sizeof(arr)/sizeof(int);

    print_array(arr, s);
    insertion_sort(arr, s);

    return 0;
}
void print_array(int* arr, int s){
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}

void insertion_sort(int* arr, int s){
    /*
    * Logic:
    * select a key value and assume it pre-sorted
    * take j=i-1 and compare key with its left side elements and shift A[j] to A[j+1] until j>=0
    * set A[j+1] = key
    */
    int key, j;
    // loop for passes. # of passes = n-1
    for (int i = 1; i <= s-1; i++)
    {
        // assuming first value to be sorted
        key = arr[i]; // assign second value to key
        j = i-1; // bcz we will compare key with its left size elements
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j]; // shift to right side
            j--;
        }
        arr[j+1] = key;
    }
    print_array(arr, s);
}