//Program to compress a string

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    cout << "Enter String : ";
    getline(cin, str);

    for(int i=0; i < str.length(); i++ )
    {
        
        if(str[i] == ' ')  continue;

        int count=1;
        cout << str[i];

        while (i+1 < str.length() && str[i+1]==str[i] )
        {
            count++;
            i++;
        }

        if (count>=1) cout << count;
        
    }    
    
    return 0;
}