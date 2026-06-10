//Program to Find largest and smallest element

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if(n<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }
    
    vector <int> arr(n);
    cout << "Enter the elements: ";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    int min=arr[0], max=arr[0];

    for( int i=0; i<n; i++)
    {
        if(arr[i] > max)  max=arr[i];
        if(arr[i] < min)  min=arr[i];
    }
    
    cout << "Largest = " << max << "\nSmallest = " << min;

    return 0;
}