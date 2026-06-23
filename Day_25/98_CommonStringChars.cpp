//Program to Find common characters in strings

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str1, str2;
    cout << "Enter String 1 : ";
    getline(cin, str1);

    cout << "Enter String 2 : ";
    getline(cin, str2);

    string same=" ";
    for(int i=0; i< str1.length(); i++)
    {
        if(str2.find(str1[i]) != string::npos)
        {
            if(same.find(str1[i]) != string::npos)
                continue;

            same += str1[i];
        }        
    }

    cout << "Common = " << same;

    return 0;
}