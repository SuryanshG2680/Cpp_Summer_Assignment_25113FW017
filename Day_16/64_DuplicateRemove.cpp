//Program to Remove duplicates from array

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
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(arr[i] == arr[j] )
            {

                for (int k=j; k<n-1; k++)
                    arr[k]=arr[k+1];

                j--;
                n--;
            }
        }
    }

    cout << "Array after removing duplicates: ";
    for (int i=0; i<n; i++)  cout << arr[i] << " ";

    return 0;
}