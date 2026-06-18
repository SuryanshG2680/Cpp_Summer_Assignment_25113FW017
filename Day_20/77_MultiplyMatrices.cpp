//Program to multiply matrices


#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int m1, n1;
    cout << "Enter number of Rows and Columns for matrix 1 : ";
    cin >> m1 >> n1;

    if(m1<=0 || n1<=0)
    {
        cout << "Invalid Matrix size";
        return 0;
    }

    int mat1[m1][n1];

    cout << "Enter elements of Matrix 1: ";
    for(int i=0; i<m1; i++){
        for(int j=0; j<n1; j++){
            cin >> mat1[i][j];
        }
    }

    int n2, m2;
    cout << "Enter number of Rows and Columns for matrix 2 : ";
    cin >> m2 >> n2;

    if(m2<=0 || n2<=0)
    {
        cout << "Invalid Matrix size";
        return 0;
    }

    int mat2[m2][n2];

    cout << "Enter elements of Matrix 2: ";
    for(int i=0; i<m2; i++){
        for(int j=0; j<n2; j++){
            cin >> mat2[i][j];
        }
    }

    if( n1 != m2 )
    { 
        cout << "The matrices can't be multiplied";
        return 1;
    }

    int result[m1][n2] = {0};
    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            for(int k=0; k<n1; k++ ){

                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    cout << "Multiplied Matrix = " << endl;
    for(int i=0; i<m1; i++){
        for(int j=0; j<n2; j++){
            cout << setw(3) << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}