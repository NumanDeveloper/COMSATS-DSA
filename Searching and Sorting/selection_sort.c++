#include <iostream>
using namespace std;

void print_array(int*, int);
void selection_sort(int*, int);

int main(){
    int arr[] = {2,1,5,22,4};
    int s = sizeof(arr)/sizeof(int);

    print_array(arr, s);
    selection_sort(arr, s);

    return 0;
}
void print_array(int* arr, int s){
    cout<<"Elements of array are:\n";
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}

void selection_sort(int* arr, int s){
    int temp, index_of_min;
    for (int i = 0; i < s-1; i++)
    {
        index_of_min = i;
        for (int j = i+1; j < s; j++)
        {
            // finding minimum element index
            if (arr[index_of_min] > arr[j])
                index_of_min = j;
        }
        temp = arr[i];
        arr[i] = arr[index_of_min];
        arr[index_of_min] = temp;
    }
    cout<<"Sorted ";
    print_array(arr, s);
}