//Program to character frequency

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    int count=0;
    cout << "Enter String : ";
    getline(cin, str);

    for(int i= 0; i< str.length()-1;){
        
        if(str[i] == ' '){
            str.erase(i, 1);
        }
        else i++;
    }

    cout  << "\nNew String (spaces removed) = " << str;

    return 0;
}