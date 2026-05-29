#include <iostream>
using namespace std;

int main()
{
    int n, fact=1;
    cout << "Enter N: ";
    cin >> n;

    for(int x=n; x>0; x--){
        fact=fact*x;
    }
    cout << "Factorial = " << fact;

    return 0;
}