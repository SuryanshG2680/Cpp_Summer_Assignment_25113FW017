//Program to find longest word 

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    cout << "Enter String  : ";
    getline(cin, str);
    str += " ";

    int count=0, maxcount=0;
    string  maxword, word="";

    for(int i=0; i < str.length(); i++ ){
        
        if(str[i] != ' ')
        {
            word += str[i];
            count++;
        }

        else
        {            
            if(count > maxcount) {
                maxcount = count;
                maxword = word;
            }
            word = "";
            count = 0;
        }   
    }
    
    cout << "Longest word is " << maxword << endl;;
    cout << "Size = " << maxcount;    
    
    return 0;
}