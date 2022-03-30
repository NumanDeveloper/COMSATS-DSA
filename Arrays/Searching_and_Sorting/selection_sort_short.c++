#include <iostream>
using namespace std;

int main(){
    int arr[5] = {2,1,5,2,4};
    int temp;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
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
    for (int k = 0; k < 5; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
    
    return 0;
}