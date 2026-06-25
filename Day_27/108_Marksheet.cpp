//Program to Create marksheet generation system
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

struct maxmarks{
    
    float intmax;
    float extmax;
    float max(){
        return intmax+extmax;
    };
};
struct totalsubjects {
    
    string name;
    float internal;
    float external;
    maxmarks max;

    float total(){
        return internal+external;
    }
    float percent(){
        return (total()/max.max())*100;
    }
    char grading(){
        if(percent() >= 90) return 'A';
        else if (percent() >= 75 && percent() < 90) return 'B';
        else if (percent() >= 60 && percent() < 75) return 'C';
        else if (percent() >= 45 && percent() < 60) return 'D';
        else if (percent() >= 30 && percent() < 45) return 'E';
        else return 'F';
    }
    
};

int main(){

    string school, board, name;
    int standard, rollnum;
    cout << "Enter School : ";
    getline(cin, school);

    cout << "Enter Board : ";
    getline(cin, board);

    cout << "Enter Student Name : ";
    getline(cin, name);

    cout << "Enetr Class : ";
    cin >> standard;

    cout << "Enter roll number : ";
    cin >> rollnum;
    
    vector<totalsubjects> sub;
    maxmarks high;

    cout << "Enter marks Range for each subject =>" << endl;
    cout << "Maximum Internal Marks of each subject : " ;
    cin >> high.intmax;
    cout << "Maximum External Marks of each subject : " ;
    cin >> high.extmax;

    int c = 0;
    char yORn;

    do{
        totalsubjects subject;
        cin.ignore();
        cout << "Enter Subject " << c+1 << " ; ";
        getline(cin, subject.name);
            
            cout << "Enter Internal Marks obtained ( /" << high.intmax << ") : ";
            cin >> subject.internal;
            cout << "Enter External Marks obtained ( /" << high.extmax << ") : ";
            cin >> subject.external;

        subject.max = high;
        sub.push_back(subject);

        cout << "Add Subject ? (y/n) ";
        cin >> yORn;
        c++;
   
    }while( yORn == 'y' || yORn == 'Y') ;
    

    cout << "*******************************    MARKSHEET    *******************************\n\n\n";

    for(char &x : school)
    x = toupper(x);

    for(char &y : board)
    y= toupper(y);

    cout << board << endl << "\n";
    cout << school << endl << "\n\n" ;
    
    cout << "Name = " << name << endl 
    << "Class = " << standard << endl
    << "Roll number = " << rollnum << endl
    << "\n\n";
    
    cout << setw(6) << "S.No." << setw(30) << "SUBJECT          "  << setw(15)
    << setw(15) << "INTERNAL" 
    << setw(15) << "EXTERNAL"
    << setw(20) << "TOTAL" 
    << setw(10) << "GRADE" << endl;

    cout << setw(6) << "" << setw(30) << "" 
    << setw(15) << ("( /"+to_string(int (high.intmax))+")") 
    << setw(15) << ("( /"+to_string(int (high.extmax))+")")
    << setw(20) << ("( /"+to_string(int (high.max()))+")")
    << setw(10) << "" << endl;

    float totalmarks=0, totalmax=0;
    c=1;
    for(totalsubjects x : sub){

        cout << setw(6) << c << ".   " 
        << left << setw(30) << x.name 
        << right << setw(15) << x.internal 
        << setw(15) << x.external
        << setw(20) << x.total()
        << setw(10) << x.grading() << endl;

        totalmarks += x.total();
        totalmax += high.max();
        c++;
    }
    cout << endl << "Total Marks = " << totalmarks << " / " << totalmax << endl;
    cout << "Percentage = " << (totalmarks/totalmax)*100 << " %" << endl;
    cout << "Status : ";
    (((totalmarks/totalmax)*100)>30)? cout << "Passed" : cout << "Fail";

        return 0;
}