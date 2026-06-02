//Check Perfect Number

#include <iostream>
using namespace std;

int main(){
    int n, sum=0;

    cout << "Enter the number= ";
    cin >> n;

    for (int i=1; i<=n/2; i++){
        if(n%i == 0){
            sum+= i;
        }
    }

    if (sum==n){
        cout << "The number is Perfect";
    }
    else {
        cout << "The number is NOT Perfect";
    }

    return 0;
}