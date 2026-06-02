//Program to Check whether a number is prime

#include <iostream>
using namespace std;

int main()
{
    int i, n, c=0;
    bool prime = false;

    cout << "Enter a number: ";
    cin >> n;
    
    if (n<=1){
    cout << "The number isn't prime or composite";
    return 1;
    }
    else {
        for (i=2; i<=n/2; i++ ){
          if (n%i == 0){
            c++;
          }
        }
    }
    if(c == 0)
    cout << "The given number is prime";
    else
    cout << "the given number is NOT prime";

    return 0;

}