//Check Strong Number (number = sum of factorials of digits)

#include <iostream>
using namespace std;

int fact(int x);

int main()
{
    int n, c, sum=0;
    cout << "Enter N: ";
    cin >> n;

    for (int x=n; x>0; x/=10){
        c = x%10;
        sum += fact(c);
    }

    if (sum==n){
        cout << "The number is Strong";
    }
    else {
        cout << "The number is NOT Strong";
    }

    return 0;
}

int fact(int x){
    int fact=1;
    for (int i=x; i>0; i--){
        fact *= i;
    }
    return fact;
}