//Program to count vowels and consonants

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    int i=0;
    cout << "Enter String : ";
    getline(cin, str);

    int vowel=0, conso=0;

    while(str[i] != 0){
        
        if( str[i] == 'a' || str[i] == 'e' 
            || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' 
            || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' 
            || str[i] == 'O' || str[i] == 'U' )
             
            vowel++;
        
        else  conso++;

        i++;
    }

    cout << "Number Of vowels = " << vowel << endl;
    cout << "Number of Consonants = " << conso;
    return 0;
}