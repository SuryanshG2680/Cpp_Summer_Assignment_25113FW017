//Program to find row wise sum

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

    //Row-wise Sum
    int sum[m] = {0};
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            sum[i] += mat[i][j];
        }
    }

    cout << "Row-wise sum= \n";
    for(int i=0; i<m; i++)
        cout << "Row " << i << "= " << sum[i] << endl;

    return 0;
}