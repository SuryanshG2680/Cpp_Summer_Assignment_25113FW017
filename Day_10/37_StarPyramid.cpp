//Program to Print star pyramid

#include <iostream>
using namespace std;

int main(){

    int rows;

    cout << "Enter number of rows : ";
    cin >> rows ;

    if(rows<=0) cout << "Invalid Size";

    for( int i=1; i<=rows; i++){
        
        //Spaces
        for (int k=rows-i; k>0; k--){
            cout << " ";
        }
        
        //Stars
        for( int j=0; j<2*i-1; j++){
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}