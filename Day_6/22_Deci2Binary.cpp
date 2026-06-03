//Convert given number from decimal to binary

#include <iostream>
using namespace std;

int main()
{
    int n, comp=1, sum=0;

    cout << "Enter N: ";
    cin >> n;
    
    while(n>0){

        sum += comp * (n%2);
        n/=2;
        comp*=10;
    }

    cout << "Binary = " << sum;

    return 0;
}