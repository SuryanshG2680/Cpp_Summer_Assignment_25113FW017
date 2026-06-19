//Program to Find string length without strlen()

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    int i=0;
    cout << "Enter String : ";
    getline(cin, str);

    while(str[i] != '\0'){
        i++;
    }

    cout << "String Length = " << i;
    return 0;
}