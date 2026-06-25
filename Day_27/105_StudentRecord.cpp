//Program to Create student record management system

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int sortfield;
struct studentslist{
    string name;
    vector<string> student;
    };
bool compareStudents(const studentslist& a, const studentslist& b )
{
    return a.student[sortfield] < b.student[sortfield];
}
bool compareStudentsNumeric(const studentslist& a, const studentslist& b )
{
    return stoi(a.student[sortfield]) < stoi(b.student[sortfield]);
};

void search(int numofstudents, int numoffields, vector<string> &field, vector<studentslist> &s){
    string name;
    bool found = false;
    cout << "Enter name to search : ";
    cin.ignore();
    getline(cin, name);
    
    for(int i=0; i<numofstudents; i++){

        if(name == s[i].name){
            found = true;
            for(int j=0; j<numoffields; j++)
            {
                cout << field[j] << " : " << s[i].student[j] << endl;
            } 
            break;
        }
    }
    if(!found) cout << "Not found\n";
    return;
}
void SORTING(int numofstudents, int numoffields, vector<string> &field, vector<studentslist> &s){
    while(true){
        int sortby;
        cout << "Enter how to sort:" << endl;
        cout << "0. None" << endl;
        cout << "1. Name" << endl;
        for (int i =0; i< field.size(); i++){
            
            cout << i+2 << ". " << field[i] << endl;
        }
        cout << field.size()+2 << ". Exit\n";
        cin >> sortby;
            
        if(sortby == field.size()+2) break;
        if(sortby == 0) break;
    
        sortfield = sortby-2;
    
        if (sortby == 1){
            sort(s.begin(), s.end(),[](const studentslist& a, const studentslist& b)
                {
                    return a.name < b.name;
                }
            );
            break;
        }

        else{
            int numeric;
            cout << "Is the Data numeric?\n1. YES\n2. NO\n";
            cin >> numeric ;
        
            if ( numeric == 1 ){
                if (sortby >= 2 && sortby <= numoffields+1) 
                sort(s.begin(), s.end(), compareStudentsNumeric);
                cout << "Sorting done\n";
                return;
            }
                
            else{
                if (sortby >= 2 && sortby <= numoffields+1) 
                    sort(s.begin(), s.end(), compareStudents);
                cout << "Sorting done\n";
                return;
            } 
        }    
    }
    return;
}
void printlist(int numofstudents, int numoffields, vector<string> &field, vector<studentslist> &s){
        for(int i=0; i<numofstudents; i++)
        {

            cout << "STUDENT " << i+1 << endl;
            cout << "Name : " << s[i].name << endl;
            for(int j=0; j<numoffields; j++)
            {
                cout << field[j] << " : " << s[i].student[j] << endl;
            }       
        } 
        return;
    }

int main(){

    //FIELD DETAILS
    cout << "Enter number of fields (excluding name): ";
    int numoffields;
    cin >> numoffields;
    
    vector<string> field(numoffields);

    cin.ignore();
    for(int i=0; i<field.size(); i++)
    {
        cout << "Enter Field " << i+1 << " name : ";
        getline(cin, field[i]);
    }
    
    //STUDENT DETAILS
    cout << "Enter number of students : ";
    int numofstudents;
    cin >> numofstudents;
    
    vector<studentslist> s(numofstudents);
    
    cin.ignore();

    for(int i=0; i < numofstudents; i++ )
    {
        s[i].student.resize(numoffields);
        cout << "Enter Student " << i+1 << " details: \n" ;

        cout << "Name : ";
        getline(cin , s[i].name);
        for(int j=0; j < numoffields; j++ )
        {
        cout << field[j] << " : " ;
        getline(cin , s[i].student[j]) ;
        
        } 
    }

    int option;
    do{
        cout << "MENU => \n"
        << "1. Sort\n"
        << "2. Search\n"
        << "3. Display list\n"
        << "4. Exit\n";
        cin >> option;
        
        switch(option){
            case 1 : SORTING(numofstudents, numoffields, field, s);
            break;
            case 2 : search(numofstudents, numoffields, field, s);
            break;
            case 3 : printlist(numofstudents, numoffields, field, s);
            break;
            case 4 : cout << "THANKYOU\n";
            return 0;
            default : cout << "Choose from options\n";
        }
    }while(option != 4);

    return 0;
}

