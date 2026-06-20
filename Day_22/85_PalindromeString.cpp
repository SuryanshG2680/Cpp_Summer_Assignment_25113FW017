//Program to check palindrome string

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    cout << "Enter String : ";
    getline(cin, str);
    string str2=str;

    for(int i= 0; i< str2.length()/2; i++){
        str2[i] = tolower(str2[i]);
        str2[str2.length()-i-1] = tolower(str2[str2.length()-i-1]);
        if(str2[str2.length()-i-1] != str2[i]){
            
            cout << "The given string is not palindrome";
            return 1;
        }
    }

    cout  << "The given string is palindrome";

    return 0;
}