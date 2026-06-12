//Program to move all zeros to end

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

    temp =0 ;
    for(int i=0; i<n; i++ )
    {
        if(arr[i] != 0){

            swap(arr[i], arr[temp]);
            temp++;
        }
    }

    cout << "After Shifting Zeros= ";
    for (int i=0; i<n; i++){
        cout << arr[i] << "  ";
    }

    return 0;
}