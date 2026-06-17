// Program to Transpose matrix

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

    cout << "Enter elements of Matrix : ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    cout << "Transpose Matrix = \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << setw(3) << mat[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}