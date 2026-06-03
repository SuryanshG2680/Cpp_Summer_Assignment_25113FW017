// Program to Find x^n without pow(). 

#include <iostream>
using namespace std;

int main(){
    int x, n;
    int pow=1;

    cout << "Enter x and n = ";
    cin >> x >> n;

    for(int i=0; i<n; i++){
        pow *= x;
    }
    
    cout << x << "^" << n << " = " << pow;

    return 0;
}