//Write the fibonacci series

#include <iostream>
using namespace std;

int main(){
    int a=0, b=1, n, c;
    
    cout << "Enter the numner of terms: ";
    cin >> n;

    cout << "   FIBONACCI SERIES\n" << a << "  " << b; 

    for(c=3; c<=n ; c++){
        int num=a+b;
        a=b;
        b=num;
        cout << "  " << num;
    }

    return 0;

}