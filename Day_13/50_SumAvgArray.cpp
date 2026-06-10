//Program to Find sum and average of array

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n, sum=0;
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

    for (int x : arr)
    {
       sum += x;
    }
    double avg= (double)sum/n;

    cout << "Sum = " << sum << "\nAverage = " << avg;
    return 0;
}