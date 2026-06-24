//Program to Create number guessing game

#include <iostream>
#include <ctime>
using namespace std;

int main(){

    srand(time(NULL));

    int guess, num, tries=0;

    num = rand() % 100  + 1;

    cout << "\n*** NUMBER GUESSING GAME ***\n\n"
    << "Computer chose a number now guess it =>\n";
    
    do{
        tries==0? cout << "Enter a number between 1 to 100 " << endl
                : cout << "Enter another number" << endl ;

        cin >> guess;
        tries++;
            
        if (guess < 1 || guess > 100) {
            cout << "Enter a number between 1 and 100\n";
            continue;
        }
        else if(num-guess >= 50)
            cout << "Your guess was Way Too Low" << endl;
        else if(num-guess >= 5 && num-guess <= 50) 
            cout << "Your guess was Too low" << endl;
        else if(num-guess < 5 && num-guess > 0)
            cout << "Your guess was Low" << endl;
        else if(num-guess > -5 && num-guess < 0)
            cout << "Your guess was High" << endl;
        else if(num-guess <= -5 && num-guess > -50)
            cout << "Your guess was Too high" << endl;
        else if(num-guess <= -50)
            cout << "Your guess was Way Too High" << endl;
            
        }  while (num != guess);
        
        cout << "Correct" << endl ;
        cout << "In " << tries << ( tries==1? " try" : " tries" ) << endl ;

    return 0;
}