//Program to Sort words by length

#include <iostream> 
#include <algorithm>
#include <string>
using namespace std;

bool compare(string a, string b) {
return a.length() < b.length();
}
int main(){

    int n;
    cout << "Enter number of words = ";
    cin >> n;
    cin.ignore();        //used to ignore the previous buffer before getlinor getline uses it

    if(n<=0)
    {
        cout << "Invalid number of words";
        return 0;
    }

    string word[n];
    cout << "Enter Words : "; 
    for (int i=0; i<n; i++)
    {
        cin >> word[i];
    }

    sort(word, word+n, compare);

    cout << endl << "Sorted Names =>" << endl; 
    for (int i=0; i<n; i++)
    {
        cout << word[i] << endl;
    }
    return 0;
}