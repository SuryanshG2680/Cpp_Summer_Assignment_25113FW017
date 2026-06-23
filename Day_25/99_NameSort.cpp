//Program to sort names alphabetically

#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

int main(){

    int n;
    cout << "Enter number of names = ";
    cin >> n;
    cin.ignore();        //used to ignore the previous buffer before getline uses it

    if(n<=0)
    {
        cout << "Invalid number of names";
        return 0;
    }

    string name[n];
    cout << "Enter Names "; 
    for (int i=0; i<n; i++)
    {
        getline(cin, name[i]);
    }

    sort(name, name+n);

    cout << endl << "Sorted Names =>" << endl; 
    for (int i=0; i<n; i++)
    {
        cout << name[i] << endl;
    }
    return 0;
}