//Program to merge two sorted arrays

#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n1, n2;
    cout << "Enter size of array 1 = ";
    cin >> n1 ;

    if(n1<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }

    int arr1[n1];
    cout << "Enter Sorted Array1 elements: ";
    for (int i=0; i<n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of array 2 = ";
    cin >> n2 
    ;
    if(n2<=0)
        {
            cout << "Invalid Array size";
            return 0;
        }

    int arr2[n2];
    cout << "Enter Sorted Array2 elements: ";
    for (int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }

    int arr3[n1+n2];
    for (int i=0; i<n1; i++)  arr3[i] = arr1[i];
    for (int i=0; i<n2; i++)  arr3[n1 +i] = arr2[i];

    sort(arr3, arr3+n1+n2);

    cout << "Sorted Merged Array: ";
    for (int i=0; i<n1+n2; i++)
    {
        cout << arr3[i] << " ";
    }

    return 0;
}