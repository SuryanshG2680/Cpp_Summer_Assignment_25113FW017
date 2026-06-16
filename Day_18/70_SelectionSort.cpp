//Program to selection sort

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

    vector <int> arr(n);
    cout << "Enter Array elements: ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    // Soting
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i; j<n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        int swap = arr[i];
        arr[i] = arr[min];
        arr[min] = swap;
    }

    cout << "Sorted array: ";
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}