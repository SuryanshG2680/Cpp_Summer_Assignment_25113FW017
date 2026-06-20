//Program to character frequency

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    int count=0;
    cout << "Enter String : ";
    getline(cin, str);

    char ch;
    cout << "Enter character to count: ";
    cin >> ch;

    for(int i= 0; i< str.length()-1; i++){
        
        if(str[i] == ch){
            count++;
        }
    }

    cout  << "Count = " << count;

    return 0;
}