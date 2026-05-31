//Find Nth Fibonacci term

#include <iostream>
using namespace std;

int main(){
    int a=0, b=1, n, c, num;
    
    cout << "Enter the #: ";
    cin >> n;

    if(n==1)
      cout << "The 1st term of Fibonacci Series is \"0\" " ;

    else if (n==2)
      cout << "The 2nd term of Fibonacci Series is \"1\" " ;

    else if (n==3)
      cout << "The 1st term of Fibonacci Series is \"1\" " ; 

    else{
        for(c=3; c<=n ; c++){
            num=a+b;
            a=b;
            b=num;
        }
        cout << "The " << n << "th term of Fibonacci Series is \"" << num <<  "\"";
    }

    return 0;

}