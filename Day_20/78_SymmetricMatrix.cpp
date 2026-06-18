//Program to check symmetric matrix

#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int m, n;
    cout << "Enter number of Rows and Columns: ";
    cin >> m >> n;

    if(m<=0 || n<=0)
    {
        cout << "Invalid Matrix size";
        return 0;
    }
    
    if(m!=n){
        cout << "Only square matrix can be symmetric";
        return 1;
    }

    int mat[m][n];

    cout << "Enter elements of Matrix: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    int c=0;
    for(int i=0; i<m; i++){
        for(int j=i; j<m; j++){
            if( mat[i][j] == mat[j][i]) 
            c++;
        }
    }

    c==(m*n)? cout << "Given matrix is symmetric"
            : cout << "Given matrix is NOT symmetric";

    return 0;
}