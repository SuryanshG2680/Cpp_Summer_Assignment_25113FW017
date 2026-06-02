//Program to Count digits in a number

#include <iostream>
using namespace std;

int main()
{
    int n, c=0;
    cout << "Enter N: ";
    cin >> n;

    for(int x=n; x>0; x/=10){
        c++;
    }
    cout << "Number of Digits = " << c;

    return 0;
}