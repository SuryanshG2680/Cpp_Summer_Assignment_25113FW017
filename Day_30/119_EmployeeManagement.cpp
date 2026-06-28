//Program to Create mini employee management system
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

struct employee{

    string name;
    long long int id;
    string job;
    int salary;
};

void Sortemployee(vector<employee> &emp);
void DeleteEmployee(vector<employee> &emp);
void Modify(vector<employee> &emp);
void Searchemployee(vector<employee> &emp);
void Display(vector<employee> &emp);
void addemployee(vector<employee> &emp);

bool cmpname( employee const &a, employee const &b){
    return a.name < b.name;
}
bool cmpjob( employee const &a, employee const &b){
    return a.job < b.job;
}
bool cmpsalary( employee const &a, employee const &b){
    return a.salary < b.salary;
}

int main(){

    string company ;
    cout << "Enter Company Name : ";
    getline(cin, company);

    int n;
    cout << "Number of Employees = " ;
    cin >> n;

    vector<employee> emp(n);

    cout << "Enter Details : \n";
    for(int i =0; i< n; i++){

        cin.ignore();
        cout << "EMPLOYEE " << i+1 << " : \n";
        cout << "Name : ";
        getline(cin, emp[i].name);
        cout << "ID (Numeric): ";
        cin >> emp[i].id;
        cin.ignore();
        cout << "Employee Designation : ";
        getline(cin, emp[i].job);
        cout << "Salary : ";
        cin >> emp[i].salary;
    }

    int option;
    do{
        cout << "Menu System: \n" 
        << "1. Add Employee\n" 
        << "2. Display employees\n"
        << "3. Search employee\n" 
        << "4. Modify employee details\n"
        << "5. Delete employee\n" 
        << "6. Sort employees\n" 
        << "7. Exit\n";

        cin >> option;

        switch(option){
            case 1 : addemployee(emp);
            break;
            case 2 : Display(emp);
            break;
            case 3 : Searchemployee(emp);
            break;
            case 4 : Modify(emp);
            break;
            case 5 : DeleteEmployee(emp);
            break;
            case 6 : Sortemployee(emp);
            break;
            case 7 : cout << "ThankYou";
                     return 0;
            default : cout << "Enter from options above\n";
            continue;         
        }
          
    }while(option != 7);

    cout << endl;

    return 0;
}

void Sortemployee (vector<employee> &emp){

    int option;
    cout << "SORT BY ? \n" << "1. Name\n" << "2. Job Designation\n" << "3. Salary\n";
    cin >> option;

    switch(option){
        case 1 : sort(emp.begin(), emp.end(), cmpname);
        cout << "Sorting by name done\n";
                break;
        case 2 : sort(emp.begin(), emp.end(), cmpjob);
        cout << "Sorting by designation done\n";
                break;
        case 3 :  sort(emp.begin(), emp.end(), cmpsalary);
        cout << "Sorting by Salary done\n";
                break;
        default : break;
    }
}
void DeleteEmployee(vector<employee> &emp){
    
    long long int search;
    cout << "Enter employee ID to Remove : " ;
    cin >> search;

    int employee_number=-1;
    for(int i=0; i<emp.size(); i++){
        if( search == emp[i].id){
            employee_number=i;
            break;
        }
    }

    if(employee_number == -1) {
        cout << "Employee not found\n";
        return ;
    }

    char yn;
    cout << "Name : " << emp[employee_number].name << endl;
    cout << "Designation : " << emp[employee_number].job << endl;
    cout << "Remove this employee? (Y/n) : " ;
    cin >> yn;
    if(yn == 'y' || yn == 'Y' ){
        emp.erase(emp.begin() + employee_number);
        cout << "Employee Removed\n";
    }
    
};
void Modify(vector<employee> &emp){

    long long int search;
    int employee_number = -1, option;
    cout << "Enter ID to modify : ";
    cin >> search;
    for(int i=0; i<emp.size(); i++){
        if( search == emp[i].id){
            employee_number=i;
            break;
        }
    }

    if(employee_number == -1) {
        cout << "Employee not found\n";
        return;
    }

    cout << "Modify : \n1. Name = " << emp[employee_number].name
    << "\n2. Job Designation = " << emp[employee_number].job 
    << "\n3. Salary = " << emp[employee_number].salary << endl;
    cin >> option;

    switch (option){
        case 1 : cout << "Enter new Name : ";
                cin.ignore();
                getline(cin, emp[employee_number].name);
                break;
        case 2 : cout << "Enter new designation : ";
                cin.ignore();
                getline(cin, emp[employee_number].job);
                break;
        case 3 : cout << "Enter new Salary : ";
                cin >> emp[employee_number].salary;
                break;
        default : cout << "Choose from options\n";
    } 
};
void Searchemployee(vector<employee> &emp){

    int option;
    do{
    
    vector<int> employee_number;
    cout << "Search by : \n1. Name\n2. ID\n3. Designation\n4. Salary\n5. Back\n";
    cin >> option;

    switch (option){
        case 1 : {
                string search;
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, search);
                for(int i=0; i<emp.size() ; i++){
                    if(search == emp[i].name) employee_number.push_back(i);
                }
                break;
            }
        case 2 : {
                long long int id;
                cout << "Enter ID : ";
                cin >> id;
                for(int i=0; i<emp.size() ; i++){
                    if(id == emp[i].id) {
                        employee_number.push_back(i);
                        break;
                    }
                }
                break;
            }
        case 3 : {
                string job;
                cout << "Enter Designation : ";
                cin.ignore();
                getline(cin, job);
                for(int i=0; i<emp.size() ; i++){
                    if(job == emp[i].job) employee_number.push_back(i);
                }
                break;
            }
        case 4 : {
                int salary;
                cout << "Enter Salary : ";
                cin >> salary;
                for(int i=0; i<emp.size() ; i++){
                    if(salary == emp[i].salary) employee_number.push_back(i);
                }
                break;
            }
        case 5 : break;

        default : cout << "Choose from options \n";
        }

            if(employee_number.empty()){
                cout << "No Record Found\n";
            }
            else{
            cout << "Search Result => \n";
            for(int i=0; i < employee_number.size(); i++){
                cout << i+1 << ". " << emp[employee_number[i]].name << endl;
                cout << "\t ID : " << emp[employee_number[i]].id << endl;
                cout << "\t Designation : " << emp[employee_number[i]].job << endl;
                cout << "\t Salary : " << emp[employee_number[i]].salary << endl;
            }
        }

    }while (option != 5);

};
void Display(vector<employee> &emp){

     for(int i =0; i< emp.size(); i++){
        cout << "EMPLOYEE " << i+1 << " : \n";
        cout << "Name : ";
        cout << emp[i].name << endl;
        cout << "ID : ";
        cout << emp[i].id << endl ;
        cout << "Designation : ";
        cout << emp[i].job << endl;
        cout << "Total Salary : ";
        cout << emp[i].salary << endl << '\n'; 
    }
};
void addemployee(vector<employee> &emp){
    employee e;

    cout << "EMPLOYEE " << emp.size()+1 << " : \n";
    cout << "Name : ";
    cin.ignore();
    getline(cin, e.name);
    cout << "ID (Numeric): ";
    cin >> e.id;
    cin.ignore();
    cout << "Job Designation : ";
    getline(cin, e.job);
    cout << "Salary : ";
    cin >> e.salary;

    emp.push_back(e);
}
