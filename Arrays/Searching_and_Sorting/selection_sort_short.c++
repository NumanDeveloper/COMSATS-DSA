#include <iostream>
using namespace std;

int main(){
    int arr[5] = {2,1,5,22,4};
    int temp, index_of_min;
    for (int i = 0; i < 5; i++)
    {
        index_of_min = i;
        for (int j = i+1; j < 5; j++)
        {
            // finding minimum element index
            if (arr[index_of_min] > arr[j])
                index_of_min = j;
        }
        temp = arr[i];
        arr[i] = arr[index_of_min];
        arr[index_of_min] = temp;
    }
    cout<<"Sorted Elements of array are:\n";
    for (int k = 0; k < 5; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
    
    return 0;
}