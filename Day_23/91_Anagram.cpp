//Program to check anagram strings
// wrong
#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str1, str2;
    cout << "Enter String 1 : ";
    getline(cin, str1);

    cout << "Enter String 2 : ";
    getline(cin, str2);

    if(str1.length() != str2.length())
    {
        cout << "The Strings are NOT Anagram" ;
        return 1;
    }

    for(int i=0; i<str1.length(); i++){
        
        char ch = str1[i];
        if(str2.find(ch) == string::npos){

            cout << "The strings are NOT anagram";
            return 1;
        }
        else{
            str2.erase(str2.begin() + str2.find(ch));
        }
    }

    cout << "The strings are anagram";

    return 0;
}

