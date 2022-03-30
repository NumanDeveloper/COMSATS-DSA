#include <iostream>
using namespace std;

int main(){
    int s = 0, e = 4, m, n;
    int arr[5] = {1,3,5,10,2};
    
    cout<<"Enter element to search: ";
    cin>>n;

    while (s <= e)
    {
        m = s + (e - s) / 2;
        if(n == arr[m]){
            cout<<n<<" found at index "<<m<<endl;
            break;
        }
        else if(n < arr[m])
            e = m-1;
        else
            s = m+1;
    }

    return 0;
}
