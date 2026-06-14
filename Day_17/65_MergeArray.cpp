//Program to Merge arrays

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n1, n2;
    cout << "Enter size of array 1 & 2 = ";
    cin >> n1 >> n2;

    if(n1<=0 || n2<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }
    
    vector <int> arr1(n1);
    cout << "Enter Array1 elements: ";
    for (int i=0; i<n1; i++){
        cin >> arr1[i];
    }
    vector <int> arr2(n2);
    cout << "Enter Array2 elements: ";
    for (int i=0; i<n2; i++){
        cin >> arr2[i];
    }

    int arr3[n1+n2];
    for (int i=0; i<n1; i++)  arr3[i] = arr1[i];
    for (int i=0; i<n2; i++)  arr3[n1 +i] = arr2[i];
    
    cout << "Merged Array: ";
    for (int i=0; i<n1+n2; i++){
        cout << arr3[i] << " ";
    }

    return 0;
}