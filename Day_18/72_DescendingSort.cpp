//Program to sort array in descending order

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

    //SORT
    for(int i=0; i<n-1; i++){

        for(int j=0; j<n-i-1; j++){

            if(arr[j] < arr[j+1]){

                int swap = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = swap;
            }
        }
    }

    cout << "Sorted array: ";
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}