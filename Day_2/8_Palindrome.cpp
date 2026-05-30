//Check whether a number is palindrome 

#include <iostream>
using namespace std;

int main()
{
    int n, c, rev=0;
    cout << "Enter N: ";
    cin >> n;

    for(int x=n; x>0; x/=10){
      c= x%10;  
      rev = rev*10 + c;
    }

  if (rev==n)
    cout << "The given number is Palindrome";
  else
   cout << "The given number is NOT Palindrome";

    return 0;
}
