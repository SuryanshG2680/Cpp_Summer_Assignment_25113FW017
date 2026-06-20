//Program to count number of words

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    int words=0;
    cout << "Enter String : ";
    getline(cin, str);

    str.append(" ");
    words=0;
    for(int i= 0; i< str.length(); i++){
        if(str[i] == ' ' && (i > 0) && str[i-1] != ' '  ){
            
            words++;
        }
    }
    cout  << "Number of words = " << words;

    return 0;
}