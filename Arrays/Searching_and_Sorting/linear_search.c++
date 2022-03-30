// Linear Search in C++

#include <iostream>
using namespace std;

int search(int array[], int s, int x)
{

    // Going through array sequencially
    for (int i = 0; i < s; i++)
        if (array[i] == x)
            return i;
    return -1;
}

int main()
{
    int array[] = {2, 4, 0, 1, 9};
    int x, s = sizeof(array) / sizeof(int);
    cout<<"Enter element to search: ";
    cin>>x;

    int result = search(array, s, x);

    (result == -1) ? cout <<x<< " not found" : cout <<x<< " found at index " << result;
}