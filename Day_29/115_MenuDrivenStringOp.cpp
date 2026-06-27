//Program to Create menu-driven string operations system
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

void display(const string &str){
    
    cout << "String = " << str << endl;
};
void length(const string &str){
    
    cout << "Length of your string is : " << str.length() << endl;
};
void reversestr(string &str){
    reverse(str.begin(), str.end());
    cout << "New ";
    display(str);
}
void uppercase(string &str){
    for(int i=0; i<str.length() ; i++){
        str[i] = toupper(str[i]);
    }
    cout << "New ";
    display(str);
};
void lowercase(string &str){
    for(int i=0; i<str.length() ; i++){
        str[i] = tolower(str[i]);
    }
    cout << "New ";
    display(str);
};
void vowelcount(const string &str){

    int count=0;
    for(char ch : str){
        ch = toupper(ch);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            count++;
    }
    cout << "Vowel Count = " << count << endl;
};
void wordcount(string &str){
    str.append(" ");
    int words=0;
    for(int i= 0; i< str.length(); i++){
        if(str[i] == ' ' && (i > 0) && str[i-1] != ' '  ){
            
            words++;
        }
    }
    cout  << "Number of words = " << words;
    str.erase(str.length()-1);
}
void palindrome(const string &str){

    string str2=str;
    for(int i= 0; i< str2.length()/2; i++){
        
        str2[i] = tolower(str2[i]);
        str2[str2.length()-i-1] = tolower(str2[str2.length()-i-1]);
        if(str2[str2.length()-i-1] != str2[i]){
            
            cout << "The given string is not palindrome\n";
            return;
        }
    }

    cout  << "The given string is palindrome\n";

    return;
}
void searchchar(const string &str){

    char ch;
    int c=0;
    vector <int> index;
    cout << "Enter character to search : ";
    cin >> ch;

    for(int i =0; i<str.length() ; i++){
        if(ch == str[i]){
            c++;
            index.push_back(i+1);
        }
    }
    if(c==0){
        cout << ch << " was not found in the string\n";
    }
    else{
        cout << ch << " was found in the string " << c << " times at positions :\n";
        for(int i=0; i<index.size(); i++){
            cout << index[i];
            if(i == index.size()-2) cout << " & ";
            else if(i== index.size()-1) cout << endl;
            else cout << ", ";
        }
    }
    return;
}
void replacestring(string &str){
    int option, option2, c=0;
    char letter, replacement;
    vector <int> index;
    do{
        cout << "Replace 1. whole string or 2. a specific character ?\n";
        cin >> option;
        if(option == 1){
            cin.ignore();
            cout << "Enter new string : ";
            getline(cin, str);
        }
        else if (option == 2){

            cout << "Enter character to replace and to replace with: ";
            cin >> letter >> replacement;
            
            for(int i =0; i<str.length() ; i++){
                if(letter == str[i]){
                    c++;
                    index.push_back(i+1);
                }
            }
            if(c==0){
                cout << letter << " was not found in the string\n";
                return;
            }
            else{
                cout << letter << " was found in the string at positions :\n";
                for(int i=0; i<index.size(); i++){
                    cout << index[i];
                    if(i == index.size()-2) cout << " & ";
                    else if(i== index.size()-1) cout << endl;
                    else cout << ", ";
                }
                do{
                    cout << "Enter Index to replace ( -1 for all & -2 for none): ";
                    cin >> option2 ;
                    
                    if(option2 == -1){
                        for(int i=0; i<index.size(); i++){
                            str[index[i]] =  replacement;
                        }
                    }
                    else if(option2 == -2){
                        break;
                    }
                    else if(find(index.begin(), index.end() , option2) != index.end()){
                        str[option2-1] = replacement;    
                        cout << "Done, next?\n";
                    }
                    else cout << "Invalid input\n";
                }while( option2 != -2 );
            }

        }
        else {
            cout << "Choose from options\n";
        }
    }while (option != 1 && option != 2);
    cout << "New ";
    display(str);
    
};
void concatenate(string &str){
    string addnew;
    cout << "Enter string to concatenate in previous string : ";
    cin.ignore();
    getline(cin, addnew);

    str.append(addnew);
    cout << "New ";
    display(str);
}
void frequency(const string &str){
    char ch;
    int c=0;
    cout << "Enter character to find frequency of : ";
    cin >> ch;

    for(char x : str){
        if(ch == x)
        c++;
    }
    if(c==0){
        cout << ch << " was not found in the string\n";
    }
    else{
        cout << ch << " frequency = " << c;
    }

    return;
}

void removeduplicates(string &str){
    
    for(int i = 0; i<str.length()-1; i++){
        for(int j=i+1; j<str.length();){
            if(str[i] == str[j]){
                str.erase(str.begin()+j);
            }
            else j++;
        }
    }
    cout << "New ";
    display(str);
}
void longestword(const string &str){

    string word="", maxword;
    for(int i=0; i<str.length(); i++){
        
        if(str[i] != ' ')
            word+=(str[i]);
        else{
            if(word.length() > maxword.length())   maxword = word;
            word = "";
        }
    }    
    if(word.length() > maxword.length())   maxword = word;

    cout << "Longest word is : " << maxword << endl;
    cout << "Length = " << maxword.length() << endl;
}

int main(){

    string str;
    int option;
    
    cout << "\n*** STRING OPERATION SYSTEM ***\n\n";

    cout << "Enter String : ";
    getline(cin, str);
    
    do{
        cout << "\nMENU =>\n"
            << "1. Display String\n"
            << "2. Find Length\n"
            << "3. Reverse String\n"
            << "4. Convert to Uppercase\n"
            << "5. Convert to lowercase\n"
            << "6. Count Vowels \n"
            << "7. Count Words\n"
            << "8. Check Palindrome\n"
            << "9. Search Character\n"
            << "10. Replace\n"
            << "11. Concatenate Another String\n"
            << "12. Find Frequency of character\n"
            << "13. Sort Characters\n"
            << "14. Remove Duplicates from the string\n"
            << "15. Longest Word\n"
            << "16. Exit\n";

        cin >> option;
        switch(option){
            case 1 : display(str);
                    break;
            case 2 : length(str);
                    break;
            case 3 : reversestr(str);
                    break;
            case 4 : uppercase(str);
                    break;
            case 5 : lowercase(str);
                    break;
            case 6 : vowelcount(str);
                    break;
            case 7 : wordcount(str);
                    break;
            case 8 : palindrome(str);
                    break;
            case 9 : searchchar(str);
                    break;
            case 10 : replacestring(str);
                    break;
            case 11 : concatenate(str);
                    break;
            case 12 : frequency(str);
                    break;
            case 13 : sort(str.begin(), str.end());
                    cout << "New ";
                    display(str);
                    break;
            case 14 : removeduplicates(str);
                    break;
            case 15 : longestword(str);
                    break;
            case 16 : cout << "*** THANK YOU ***\n";
                    return 0;
            default : cout << "Choose from given operations to perform\n";
        }
    }while (option != 16);

    return 0;
}
