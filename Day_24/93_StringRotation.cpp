//Program to check string rotation

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str1, str2;
    cout << "Enter String 1 : ";
    getline(cin, str1);

    cout << "Enter String 2 : ";
    getline(cin, str2);

    bool found=false;

    if(str1.length() != str2.length())
        found = false;

    if((str1+str1).find(str2) < str1.length() )
    {
        found = true;
    }

    found? cout << "ROTATION"
         : cout << "NOT ROTATION";

    return 0;
}

