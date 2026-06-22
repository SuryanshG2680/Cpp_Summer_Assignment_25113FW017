//Program to remove duplicate characters

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    cout << "Enter String  : ";
    getline(cin, str);

    for(int i=0; i < str.length()-1; i++ ){

        for (int j=i+1; j< str.length()-1; j++){

            if(str[i] == str[j]) {
                str.erase(j, 1);
            }
        }
        
    }

    cout << "New String : " << str << endl;
    return 0;
}