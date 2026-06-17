// Program to Add matrices

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

    int mat1[m][n], mat2[m][n];

    cout << "Enter elements of Matrix 1: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat1[i][j];
        }
    }

    cout << "Enter elements of Matrix 2: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat1[i][j];
        }
    }

    cout << "Sum = \n";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout << setw(3) << (mat2[i][j] + mat1[i][j]) << " ";
        }
        cout << endl;
    }

    return 0;
}