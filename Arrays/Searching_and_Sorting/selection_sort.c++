#include <iostream>
using namespace std;

void print_array(int*, int);
void selection_sort(int*, int);
int main(){
    int s;
    cout<<"Enter size of array: ";
    cin>>s;
    int arr[s];
    cout<<"Enter array elements:\n";
    for (int i = 0; i < s; i++)
        cin>>arr[i];
    
    print_array(arr, s);
    selection_sort(arr, s);

    return 0;
}
void print_array(int* arr, int s){
    cout<<"Unsorted Elements of array are:\n";
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}

void selection_sort(int* arr, int s){
    int temp;
    for (int i = 0; i < s-1; i++)
    {
        for (int j = i+1; j < s; j++)
        {
            // sorting in ascending order
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout<<"Sorted Elements of array are:\n";
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}