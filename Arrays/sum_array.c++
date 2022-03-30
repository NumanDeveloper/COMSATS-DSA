#include <iostream>
using namespace std;

void sum(int* arr, int size);
int main(){
    int arr[] = {2,34,52,4,2,1,56};
    int size = sizeof(arr)/sizeof(int);
    sum(arr, size);
    
    return 0;
}
void sum(int* arr, int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    cout<<"The sum is: "<<sum<<endl;
}