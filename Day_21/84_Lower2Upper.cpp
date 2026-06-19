//Program to convert lowercase to uppercase

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){

    string str;
    int i=0;
    cout << "Enter String : ";
    getline(cin, str);

    cout << "The string in uppercase is= ";

    for(int i= 0 ; i<str.length() ; i++)
    {
        str[i] = toupper(str[i]);
        cout << (str[i]);
    }

    return 0;
}