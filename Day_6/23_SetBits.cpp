// Program to count set bits in a number

#include <iostream>
using namespace std;

int main(){
    int n, count=0;

    cout << "Enter N: ";
    cin >> n;

    for(int i=n; i>0; i/=2){   //diving by 2 basically means shifting 1 bit right
                               // can be written as ( i >>= 1 )
            count+= (i & 1);   // i&1 means last bit of n AND 1 
        }
    

    cout << "Set Bits = " << count;
    
    return 0;
}