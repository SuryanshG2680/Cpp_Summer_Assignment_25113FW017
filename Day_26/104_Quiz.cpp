//Program to create quiz application

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main(){

    string ques[]={"What is the national animal of India?",
                "What is the national bird of India?",
                "What is the national flower of India?",	
                "What is the national tree of India?",
                "What is the national anthem of India?",	
                "What is the national aquatic animal of India?",
                "What is the national sport of India?",
                "What is the national currency of India?",
                "What is the national river of India?",
                "What is the name of the Indian national flag?"};
    
    string option[10][4] = {{"a) Lion", "b) Elephant", "c) Tiger",  "d) Leopard"},
                {"a) Parrot",  "b) Pigeon",  "c) Peacock",  "d) Sparrow"},
                {"a) Rose",  "b) Lotus",  "c) Lily",  "d) Jasmine"},
                {"a) Banyan",  "b) Ashoka",  "c) Eucalyptus",  "d) Neem"},
                {"a) Vande Mataram",  "b) Jana-Gana-Mana",  "c) Saare Jahaan se Accha",  "d) Maa Tujhe Salaam"},
                {"a) Blue Whale",  "b) Shark",  "c) Octopus",  "d) Ganges River Dolphin"},
                {"a) Hockey",  "b) Cricket",  "c) Basketball",  "d) Kabaddi"},
                {"a) Dollar",  "b) Yen",  "c) Euro",  "d) Indian Rupee"},
                {"a) Brahmaputra",  "b) Chenab",  "c) Ganga",  "d) Narmada"},  
                {"a) Tricolour",  "b) Flag",  "c) Duo colour",  "d) Pentacolour"}};
            
    char guess[10], answer[]={'c','c','b','a','b','d','a','d','c','a'};

    cout << "\n~~~~~~ NATIONAL SYMBOLS QUIZ ~~~~~~ \n" << endl;

    string start;
    cout << "Press Enter to start or 'E' to end the quiz \n";
    getline(cin, start);

    start[0] = toupper(start[0]);
    if (start == "E" ) { 
        cout << "Thankyou";
        return 0;
    }
    cout << endl;

    int qnum=0, marks=0;
    int totalques=(sizeof(ques)/sizeof(ques[0]));

    cout << "You can use 1, 2, 3, 4, a, b, c, d, or A, B, C, D to answer\n";
    do{
        cout << "Q" << qnum+1 << ". " << ques[qnum] << endl;
        
        for(int i=0; i<4; i++){
            cout << option[qnum][i] << endl;
        }

        newguess:
        cin >> guess[qnum];

        switch(guess[qnum]){
            case '1' : { guess[qnum]='a'; 
                        break;   }
            case '2' : { guess[qnum]='b'; 
                        break;   }
            case '3' : { guess[qnum]='c'; 
                        break;   }
            case '4' : { guess[qnum]='d'; 
                        break;   }
        }

        guess[qnum] = tolower(guess[qnum]);

        if (guess[qnum] != 'a' && guess[qnum] != 'b'&& guess[qnum]!='c' && guess[qnum]!='d')
            {
                cout << "Choose from options above\n";
                goto newguess;
            }
        if (guess[qnum] == answer[qnum]) {
            cout << "CORRECT" << endl; 
            marks++;
        }
        else{
            cout << "WRONG\nCorrect Answer: " << answer[qnum] << endl;
        }
        
        qnum++;
    } while (qnum != totalques);

    cout << "MARKS : " << marks << " / 10\n";
    cout << "PERCENTAGE : " << (marks*10)<< " %" << endl;

    cout << "**********\nThankyou";
    return 0;
}