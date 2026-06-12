//Program to right rotate an array

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

    temp=arr[n-1];
    for(int i=n-1; i>0; i-- )
    {
        arr[i]=arr[i-1];
    }
    arr[0]=temp;

    cout << "Right Rotated Array= ";
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}