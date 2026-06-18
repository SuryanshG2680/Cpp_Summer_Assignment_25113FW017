//Program to find column wise sum

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

    cout << "Enter elements of Matrix: ";
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }

    //Column-wise Sum
    int sum[n] = {0};
    for(int j=0; j<n; j++){
        for(int i=0; i<m; i++){
            sum[j] += mat[i][j];
        }
    }

    cout << "Column-wise sum= ";
    for(int i=0; i<n; i++)
        cout << sum[i] << "  ";

    return 0;
}