#include <iostream>
using namespace std;

void print_array(int*, int);
void binary_search(int*, int);
int main(){
    int s;
    cout<<"Enter size of array: ";
    cin>>s;
    int arr[s];
    cout<<"Enter array elements:\n";
    for (int i = 0; i < s; i++)
        cin>>arr[i];
    
    print_array(arr, s);
    binary_search(arr, s);

    return 0;
}
void print_array(int* arr, int s){
    cout<<"Elements of array are:\n";
    for (int k = 0; k < s; k++)
        cout<<arr[k]<<" | ";
    cout<<"\n";
}

void binary_search(int* arr, int size){
    bool found = false;
    int s = 0, e = size-1, m, n;
    cout<<"Enter element to search: ";
    cin>>n;

    while (s <= e)
    {
        m = s + (e - s) / 2;
        if(n == arr[m]){
            cout<<n<<" found at index "<<m<<endl;
            found = true;
            break;
        }
        else if(n < arr[m])
            e = m-1;
        else
            s = m+1;
    }
    if(found == false)
        cout<<n<<" is not found in array !!"<<endl;
}