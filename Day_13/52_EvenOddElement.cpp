//Program to Count even and odd elements

#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n;  
    cout << "Enter number of elements: ";  
    cin >> n;  

    if(n<=0) 
    {
        cout << "Invalid Array size";
        return 0;
    }

    vector <int> arr(n);
    cout << "Enter the elements: "; 
    for (int i=0; i<n; i++)
    {  
        cin >> arr[i];  
    }  
  
    int evencount=0, oddcount=0;  
    for (int i=0; i<n; i++)
    {  
        if(arr[i]%2==1) 
            oddcount++ ;

        else
            evencount++ ;  
    }  
  
    cout << "Number of even elements =" << evencount << endl;  
    cout << "Number of Odd elements =" << oddcount;  

    return 0;

}