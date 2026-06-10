//program to Input and display array

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout << "Enter size of array = ";
    cin >> n;

    if(n<=0) 
    {
        cout << "Invalid Array size";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter Array elements: ";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "The elements of the array are: \n";
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}