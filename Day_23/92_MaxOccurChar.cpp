//Program to Find maximum occurring character

#include <iostream> 
#include <string>
using namespace std;

int main(){

    string str;
    cout << "Enter String  : ";
    getline(cin, str);

    int maxfreq=0, freq;
    char maxch;

    for(int i=0; i < str.length()-1; i++ ){

        freq=0;
        if(str[i] == ' ') continue;

        for (int j=0; j< str.length()-1; j++){

            if(str[i] == str[j]) {
                freq++;
            }
        }
        if(freq > maxfreq){
            maxfreq=freq;
            maxch = str[i];
        }
    }

    cout << "Character with max occurence = " << maxch << endl;
    cout << "Frequency = " << maxfreq;
    return 0;
}