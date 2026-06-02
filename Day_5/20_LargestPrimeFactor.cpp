//Finf the largest prime factor

#include <iostream>
using namespace std;

int main(){
    
    int i, n, prime=-1;

    cout << "Enter a number: ";
    cin >> n;

    for(int i=2; i<=n/2 ; i++){
        if( n%i==0 ){
            int c=0;

            for(int j=2; j<i; j++){
                if(i%j == 0)
                    c++;
            }
            if(c==0)
                prime=i;
        }
    }

    cout << "The largest prime factor is ";

    if(prime==-1)
        cout << n;
    else
        cout << prime;

    return 0;
}