#include <iostream>
using namespace std;
// CAUTION: Array must be sorted in order to use binary search 
int main(){
    int s = 0, e = 6, m, n;
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};
    
    cout<<"Enter element to search: ";
    cin>>n;

    while (s <= e)
    {
        m = (s + e) / 2;
        if(n == arr[m]){
            cout<<n<<" found at index "<<m<<endl;
            break;
        }
        else if(n < arr[m])
            e = m-1; // take left half
        else
            s = m+1; // take right half
    }

    return 0;
}
