//Find all Factors of given Number

#include <iostream>
using namespace std;

int main()
{
    int i, n, c=0;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factors of "<< n << " are\n";

    for (i=1; i<=n/2; i++ ){
        if (n%i == 0){
            cout << i << " , ";
          }
        }

    cout << "and " << n;
    return 0;

}