//Check Armstrong Number

#include <iostream>
using namespace std;

int pow(int x, int y);
int main(){
    
    int n, arm=0, digit=0, c;

    cout << "Enter the number= ";
    cin >> n;

    for(int x=n; x>0; x/=10){
        digit++;
    }
 
    for(int x=n; x>0; x/=10){
        c= x%10;
        arm= arm + pow(c, digit);
    }

    if(n == 0){
        cout << "The given number is NOT Armstrong";
        return 1;
    }

    else if(n==arm){
        cout << "The given number is Armstrong";
    }
    
    else  
        cout << "The given number is NOT Armstrong";

    return 0;
}

int pow(int x, int y){
    int pow=1;

    for(int i=0; i<y; i++){
        pow=pow * x;
    }
    return pow;
}