//Program to Print number pyramid

#include <iostream>
using namespace std;

int main(){

    int rows, c;

    cout << "Enter number of rows : ";
    cin >> rows ;

    for( int i=1; i<=rows; i++){
        c=1;
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