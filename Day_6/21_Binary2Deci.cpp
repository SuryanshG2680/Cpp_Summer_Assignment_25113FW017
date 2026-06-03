//Convert given number from binary to decimal

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, sum=0, i=0, c;
    cout << "Enter N: ";
    cin >> n;

    for(int x=n; x>0; x/=10){
        c = x%10;
        if (c != 1 && c!= 0){
            cout << "Error !!! Enter binary term ";
            return 1;
        }
        sum += c*pow(2, i);
        i++;       
    }

    cout << "Decimal = " << sum;
    return 0;
}