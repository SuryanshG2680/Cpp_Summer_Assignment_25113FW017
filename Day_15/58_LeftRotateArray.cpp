//Program to left rotate an array

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, temp;
    cout << "Enter size of array = ";
    cin >> n;

    if(n<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }

    vector <int> arr(n);
    cout << "Enter Array elements: ";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    temp=arr[0];
    for(int i=0; i<n-1; i++ )
    {
        arr[i]=arr[i+1];
    }
    
    arr[n-1]=temp;

    cout << "Left Rotated Array= ";
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}