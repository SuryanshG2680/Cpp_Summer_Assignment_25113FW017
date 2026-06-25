//Program to Create employee record management system

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sortfield;

struct employeelist{
    string name;
    vector<string> employee;
};
bool compareEmployee(const employeelist& a, const employeelist& b)
{
    return a.employee[sortfield] < b.employee[sortfield];
}
bool compareEmployeeNumeric(const employeelist& a, const employeelist& b)
{
    return stoi(a.employee[sortfield]) < stoi(b.employee[sortfield]);
}

void search(int numofemployee, int numoffields, vector<string> &field, vector<employeelist> &s)
{
    string name;
    cout << "Enter name to search : ";

    cin.ignore();
    getline(cin, name);

    bool found = false;

    for(int i=0; i<numofemployee; i++) {
        
        if(name == s[i].name) {
            found = true;

            cout << "Name : " << s[i].name << endl;
            for(int j=0; j<numoffields; j++) {
                cout << field[j]
                << " : "
                << s[i].employee[j]
                << endl;
            }
            break;
        }
    }

    if(!found) cout << "Employee not found\n";
    return;
}

void SORTING(int numofemployee, int numoffields, vector<string> &field, vector<employeelist> &s) {
    while(true) {
        
        int sortby;
        cout << "Enter how to sort:" << endl;
        cout << "0. None" << endl;
        cout << "1. Name" << endl;

        for(int i=0; i<field.size(); i++) {
            cout << i+2 << ". "
                 << field[i]
                 << endl;
        }

        cout << field.size()+2 << ". Exit\n";

        cin >> sortby;

        if(sortby == field.size()+2)
            break;

        if(sortby == 0)
            break;

        if(sortby == 1) {
            sort(s.begin(), s.end(),
                [](const employeelist& a,
                const employeelist& b) {
                    return a.name < b.name;
                }
            );
            break;
        }

        sortfield = sortby - 2;

        int numeric;

        cout << "Is the Data numeric?\n";
        cout << "1. YES\n";
        cout << "2. NO\n";

        cin >> numeric;

        if(numeric == 1) {
            if(sortby >= 2 && sortby <= numoffields + 1) {
                sort(s.begin(), s.end(), compareEmployeeNumeric);
            }
        }
        else {
            if(sortby >= 2 && sortby <= numoffields + 1) {
                sort(s.begin(), s.end(), compareEmployee);
            }
        }

        break;
    }
}

void printlist(int numofemployee, int numoffields, vector<string> &field, vector<employeelist> &s) {
    for(int i=0; i<numofemployee; i++) {
        cout << "EMPLOYEE " << i+1 << endl;

        cout << "Name : " << s[i].name << endl;

        for(int j=0; j<numoffields; j++) {
            cout << field[j]
                 << " : "
                 << s[i].employee[j]
                 << endl;
        }
    }
}

int main()
{
    //FIELD DETAILS
    cout << "Enter number of fields (excluding name): ";

    int numoffields;
    cin >> numoffields;

    vector<string> field(numoffields);

    cin.ignore();

    for(int i=0; i<field.size(); i++) {
        cout << "Enter Field "
             << i+1
             << " name : ";

        getline(cin, field[i]);
    }

    //EMPLOYEE DETAILS
    cout << "Enter number of employees : ";

    int numofemployee;
    cin >> numofemployee;

    vector<employeelist> s(numofemployee);

    cin.ignore();

    for(int i=0; i<numofemployee; i++) {
        s[i].employee.resize(numoffields);

        cout << "Enter Employee " << i+1 << " details:\n";

        cout << "Name : ";
        getline(cin, s[i].name);

        for(int j=0; j<numoffields; j++) {
            cout << field[j] << " : ";
            getline(cin, s[i].employee[j]);
        }
    }

    int option;
    do {
        cout << "MENU => \n"
             << "1. Sort\n"
             << "2. Search\n"
             << "3. Display list\n"
             << "4. Exit\n";

        cin >> option;

        switch(option)
        {
            case 1: SORTING(numofemployee, numoffields, field, s);
                break;
            case 2: search(numofemployee, numoffields, field, s);
                break;
            case 3: printlist(numofemployee, numoffields, field, s);
                break;
            case 4: cout << "THANKYOU\n";
                return 0;
            default: cout << "Choose from options\n";
        }

    }while(option != 4);

    return 0;
}