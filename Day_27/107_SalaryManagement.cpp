//Program to Create salary management system
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

struct package{
    long double base;
    double bonus;
    double deduction;
};
struct employee{

    string name;
    long long int id;
    string job;
    struct package salary ;
    long double totalsalary() const{
        return ( salary.base + salary.bonus - salary.deduction );
    }
};

void Sortemployee(vector<employee> &emp);
void DeleteEmployee(vector<employee> &emp);
void ModifySalary(vector<employee> &emp);
void Searchemployee(vector<employee> &emp);
void Display(vector<employee> &emp);
void addemployee(vector<employee> &emp);

bool cmpname( employee const &a, employee const &b){
    return a.name < b.name;
}
bool cmpjob( employee const &a, employee const &b){
    return a.job < b.job;
}
bool cmptotalsalary( employee const &a, employee const &b){
    return a.totalsalary() < b.totalsalary();
}
bool cmpbasesalary( employee const &a, employee const &b){
    return a.salary.base < b.salary.base;
}
bool cmpbonussalary( employee const &a, employee const &b){
    return (a.salary.bonus+a.salary.base) < (b.salary.bonus+b.salary.base);
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
        cin >> emp[i].salary.base;
        cout << "Bonus : ";
        cin >> emp[i].salary.bonus;
        cout << "Deductions : ";
        cin >> emp[i].salary.deduction;
    }

    int option;
    do{
        cout << "Menu System: \n" << "0. Exit\n"
        << "1. Add Employee\n" << "2. Display employees\n"
        << "3. Search employee\n" << "4. Modify salary\n"
        << "5. Delete employee\n" << "6. Sort employees\n" ;

        cin >> option;

        switch(option){
            case 0 : cout << "ThankYou";
                     return 0;
            case 1 : addemployee(emp);
                     break;
            case 2 : Display(emp);
                    break;
            case 3 : Searchemployee(emp);
                     break;
            case 4 : ModifySalary(emp);
                     break;
            case 5 : DeleteEmployee(emp);
                     break;
            case 6 : Sortemployee(emp);
                     break;
            default : cout << "Enter from options above\n";
                     continue;         
        }
          
    }while(option != 0);

    cout << endl;

    return 0;
}

void Sortemployee (vector<employee> &emp){

    int option;
    cout << "SORT BY ? \n" << "1. Name\n" << "2. Job Description\n" << "3. Salary\n";
    cin >> option;

    switch(option){
        case 1 : sort(emp.begin(), emp.end(), cmpname);
                break;
        case 2 : sort(emp.begin(), emp.end(), cmpjob);
                break;
        
        case 3 : int salarysortoption;
                cout << "SALARY SORT :\n1. Base Salary\n2. Base + Bonus \n3. Total Salary\n";
                cin >> salarysortoption;
                switch (salarysortoption){
                    case 1 : sort(emp.begin(), emp.end(), cmpbasesalary);
                            break;
                    case 2 : sort(emp.begin(), emp.end(), cmpbonussalary);
                            break;
                    default : sort(emp.begin(), emp.end(), cmptotalsalary);
                            break;
                }
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
        if( search == emp[i].id) employee_number=i;
    }

    if(employee_number == -1) return ;

    char yn;
    cout << "Name : " << emp[employee_number].name << endl;
    cout << "Designation : " << emp[employee_number].job << endl;
    cout << "Remove this employee? (Y/n) : " ;
    cin >> yn;
    if(yn == 'y' || yn == 'Y' ) emp.erase(emp.begin() + employee_number);
    
};
void ModifySalary(vector<employee> &emp){

    long long int search;
    int employee_number = -1, option;
    cout << "Modify Salary of (Enter ID) : ";
    cin >> search;
    for(int i=0; i<emp.size(); i++){
        if( search == emp[i].id) employee_number=i;
    }

    if(employee_number == -1) {
        cout << "Employee not found\n";
        return;
    }

    cout << "Total Salary of " << emp[employee_number].name << " is = " << emp[employee_number].totalsalary() << endl;
    cout << "Modify : \n1. Base Salary = " << emp[employee_number].salary.base 
    << "\n2. Bonus = " << emp[employee_number].salary.bonus 
    << "\n3. Deductions = " << emp[employee_number].salary.deduction << endl;
    cin >> option;

    switch (option){
        default : cout << "Enter new Salary : ";
                cin >> emp[employee_number].salary.base;
                break;
        case 2 : cout << "Enter new Bonus : ";
                cin >> emp[employee_number].salary.bonus;
                break;
        case 3 : cout << "Enter new Deduction : ";
                cin >> emp[employee_number].salary.deduction;
                break;
    } 
};
void Searchemployee(vector<employee> &emp){

    int option;
    do{
    
    vector<int> employee_number;
    cout << "Search by : \n1. Name\n2. ID\n3. Designation\n4. Salary\n5. Bonus\n6. Total Salary\n7. Back\n";
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
                    if(id == emp[i].id) employee_number.push_back(i);
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
                double basesalary;
                cout << "Enter Salary : ";
                cin >> basesalary;
                for(int i=0; i<emp.size() ; i++){
                    if(basesalary == emp[i].salary.base) employee_number.push_back(i);
                }
                break;
            }
        case 5 : {
                double bonus;
                cout << "Enter Bonus : ";
                cin >> bonus;
                for(int i=0; i<emp.size() ; i++){
                    if(bonus == emp[i].salary.bonus) employee_number.push_back(i);
                }
                break;
            }
        case 6 : {
                double salary;
                cout << "Enter Total Salary : ";
                cin >> salary;
                for(int i=0; i<emp.size() ; i++){
                    if(salary == emp[i].totalsalary()) employee_number.push_back(i);
                }
                break;
            }
        case 7 : break;

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
                cout << "\t Total Salary : " << emp[employee_number[i]].totalsalary() << endl;
                cout << "\t Bonus : " << emp[employee_number[i]].salary.bonus << endl;
            }
        }

    }while (option != 7);

};
void Display(vector<employee> &emp){

     for(int i =0; i< emp.size(); i++){
        cout << "EMPLOYEE " << i+1 << " : \n";
        cout << "Name : ";
        cout << emp[i].name << endl;
        cout << "ID : ";
        cout << emp[i].id << endl << '\n';
        cout << "Designation : ";
        cout << emp[i].job << endl << '\n';
        cout << "Total Salary : ";
        cout << emp[i].totalsalary() << endl << '\n';
        cout << "Salary Package : ";
        cout << emp[i].salary.base << endl << '\n';
        cout << "Bonus : ";
        cout << emp[i].salary.bonus << endl << '\n';
        cout << "Deductions : ";
        cout << emp[i].salary.deduction << endl << '\n';
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
    cout << "Job Description : ";
    getline(cin, e.job);
    cout << "Salary Package : ";
    cin >> e.salary.base;
    e.salary.bonus=0;
    e.salary.deduction=0;

    emp.push_back(e);
}