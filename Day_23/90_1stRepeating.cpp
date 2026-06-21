//Program to find first repeating character

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    cout << "Enter String : ";
    getline(cin, str);

    for(int i= 0; i< str.length()-1; i++){
        
        int c=0;
        if(str[i] == ' ') continue;
        for(int j=0; j< str.length()-1; j++){
            
            if(str[i] == str[j]) c++;
        }
        if (c>1) {
            cout << "First Repeating character is = " << str[i];
            return 1;
        }
    }
    cout << "All characters repeat atleast once";

    return 0;
}