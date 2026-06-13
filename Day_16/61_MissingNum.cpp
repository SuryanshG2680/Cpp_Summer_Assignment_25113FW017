//Program to Find missing number in array

#include <iostream>
using namespace std;

bool duplicatefound (int, int arr[]);
int main(){

    int n;
    cout << "Enter size of array = ";
    cin >> n;

    if(n<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }

    int arr[n];
    cout << "Enter Array elements from 0 to " << n << ": ";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    if (duplicatefound(n, arr))
    {
        cout << "Duplicates found" << endl;
        cout << "Program Terminated";
        return 1;
    }

    int sum=0, total= (n*(n+1))/2;
     
    for(int i=0; i<n; i++)
    {
        if(arr[i] < 0 || arr[i] > n)
        {
            cout << "Out of range elements found" << endl;
            cout << "Program Terminated";
            return 1;
        }
        sum += arr[i];
    }

    cout << total - sum << " is missing";

    return 0;
}

bool duplicatefound (int n, int arr[]){

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (arr[i] == arr[j])  return true;
        }
    }
    return false;

}