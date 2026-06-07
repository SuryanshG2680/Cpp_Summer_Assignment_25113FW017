//Program to Print character pyramid

#include <iostream>
using namespace std;

int main(){

    int rows;
    char c;

    cout << "Enter number of rows : ";
    cin >> rows ;

    if(rows<0) cout << "Invalid Size";

    for( int i=1; i<=rows; i++){
        c='A';

        if(i>26){
            cout << "Limit Exceeded";
            return 0;
        }

        //Spaces
        for (int k=rows-i; k>0; k--){
            cout << " ";
        }
        
        //Increment
        for( int j=0; j<i; j++){
            cout << c++;
        }
        
        //Decrement
        --c;
        for( int j=i; j< 2*i-1; j++){
            cout << --c;
        }

        cout << endl;
    }

    return 0;
}