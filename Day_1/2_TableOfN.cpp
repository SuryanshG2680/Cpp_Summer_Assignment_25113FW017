//Print multiplication table of a given number

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n, sum;
    cout << "Enter N: ";
    cin >> n;

    for(int i=1; i<=10; i++){
        cout << setw(2) << n << " *" << setw(2) 
        << i << " =" << setw(3) << n*i << "\n";
    }
    
    return 0;
}