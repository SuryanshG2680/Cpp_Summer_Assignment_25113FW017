//Print Armstrong number in a range

#include <iostream>
using namespace std;


int pow(int x, int y){
    int pow=1;

    for(int i=0; i<y; i++){
        pow=pow * x;
    }
    return pow;
};

int main(){

    int start, end, i, digit=0, c,arm=0;

    cout << "Enter start and end: ";
    cin >> start >> end;

    for (int i=start; i<=end; i++){

         digit=0;
         arm=0;

        for(int x=i; x>0; x/=10){
        digit++;
        }
 
        for(int x=i; x>0; x/=10){
        c= x%10;
        arm= arm + pow(c, digit);
        }

        if(arm==i){
            cout << i << "\n" ;
        }
    }

    return 0;

}