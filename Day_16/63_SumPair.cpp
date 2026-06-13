//Problem to find pair with given sum

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

    int num, c=0;
    cout << "Enter sum to search pair for = ";
    cin >> num;

    for(int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if(arr[i]+arr[j] == num)
            {
                cout << arr[i] << " + " << arr[j] << endl;
                c++;
            }
        }
    }
    if(c==0) cout << "No pair sum to " << num;

    return 0;
}