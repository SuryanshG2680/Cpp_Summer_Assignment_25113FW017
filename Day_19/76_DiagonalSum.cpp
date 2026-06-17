// Program to find diagonal sum

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

    int mat[m][n];
    if(m != n) cout << "The matrix is not square" << endl;

    cout << "Enter elements of Matrix : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    

    int sum=0;
    for(int i=0; i<(n<m? n: m); i++)
    {
            sum += mat[i][i];
    }
    
    cout << "Sum of Diagonal elements = " << sum;
    return 0;
}