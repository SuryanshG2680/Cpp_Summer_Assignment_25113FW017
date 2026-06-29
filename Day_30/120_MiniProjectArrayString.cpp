//Program to Develop complete mini project using arrays, strings and functions
 
// Employee Management using arrays, strings and functions

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

vector<int> id;
vector<string> name;
vector<string> department;
vector<double> salary;

void display();
void add();
void search();
void update();
void removeemployee();
void incrementsalary();
void highestsalary();
void sortid();
void sortname();

int main(){

    int option;

    cout<<"***** EMPLOYEE MANAGEMENT SYSTEM *****\n";

    do{

        cout<<"\nMENU\n";
        cout<<"1. Add Employee\n";
        cout<<"2. Display Employees\n";
        cout<<"3. Search Employee\n";
        cout<<"4. Update Employee\n";
        cout<<"5. Remove Employee\n";
        cout<<"6. Increase Salary\n";
        cout<<"7. Highest Salary\n";
        cout<<"8. Sort By ID\n";
        cout<<"9. Sort By Name\n";
        cout<<"10. Exit\n";

        cin>>option;

        switch(option){

            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: removeemployee(); break;
            case 6: incrementsalary(); break;
            case 7: highestsalary(); break;
            case 8: sortid(); break;
            case 9: sortname(); break;
            case 10: cout<<"*** THANK YOU ***";
                     return 0;
            default: cout<<"Choose Correct Option\n";
        }

    }while(option!=10);

    return 0;
}

void add(){

    int empid;
    string empname, dept;
    double pay;

    cout<<"Employee ID : ";
    cin>>empid;

    for(int x:id){
        if(x==empid){
            cout<<"ID Already Exists\n";
            return;
        }
    }

    cin.ignore();

    cout<<"Employee Name : ";
    getline(cin,empname);

    cout<<"Department : ";
    getline(cin,dept);

    cout<<"Salary : ";
    cin>>pay;

    while(pay<0){
        cout<<"Invalid Salary : ";
        cin>>pay;
    }

    id.push_back(empid);
    name.push_back(empname);
    department.push_back(dept);
    salary.push_back(pay);

    cout<<"Employee Added Successfully\n";
}

void display(){

    if(id.empty()){
        cout<<"No Employees Found\n";
        return;
    }

    for(int i=0;i<id.size();i++){

        cout<<"\nEmployee "<<i+1<<endl;

        cout<<"ID         : "<<id[i]<<endl;
        cout<<"Name       : "<<name[i]<<endl;
        cout<<"Department : "<<department[i]<<endl;
        cout<<"Salary     : "<<salary[i]<<endl;

        cout<<"--------------------------\n";
    }
}
void search(){

    if(id.empty()){
        cout<<"No Employees Found\n";
        return;
    }

    int option;

    cout<<"Search By\n";
    cout<<"1. ID\n";
    cout<<"2. Name\n";
    cin>>option;

    if(option==1){

        int empid;

        cout<<"Enter ID : ";
        cin>>empid;

        for(int i=0;i<id.size();i++){

            if(id[i]==empid){

                cout<<"\nEmployee Found\n";

                cout<<"ID         : "<<id[i]<<endl;
                cout<<"Name       : "<<name[i]<<endl;
                cout<<"Department : "<<department[i]<<endl;
                cout<<"Salary     : "<<salary[i]<<endl;

                return;
            }
        }

        cout<<"Employee Not Found\n";
    }

    else if(option==2){

        string empname;

        cin.ignore();
        cout<<"Enter Name : ";
        getline(cin,empname);

        transform(empname.begin(),empname.end(),empname.begin(),::tolower);

        bool found=false;

        for(int i=0;i<name.size();i++){

            string temp=name[i];
            transform(temp.begin(),temp.end(),temp.begin(),::tolower);

            if(temp.find(empname)!=string::npos){

                found=true;

                cout<<"\nID         : "<<id[i]<<endl;
                cout<<"Name       : "<<name[i]<<endl;
                cout<<"Department : "<<department[i]<<endl;
                cout<<"Salary     : "<<salary[i]<<endl;
            }
        }

        if(!found)
            cout<<"Employee Not Found\n";
    }

    else
        cout<<"Invalid Option\n";
}
void update(){

    int empid;

    cout<<"Enter Employee ID : ";
    cin>>empid;

    for(int i=0;i<id.size();i++){

        if(id[i]==empid){

            int option;

            do{

                cout<<"\nUpdate\n";
                cout<<"1. Name\n";
                cout<<"2. Department\n";
                cout<<"3. Salary\n";
                cout<<"4. Exit\n";

                cin>>option;

                switch(option){

                    case 1:
                        cin.ignore();
                        cout<<"Enter New Name : ";
                        getline(cin,name[i]);
                        break;

                    case 2:
                        cin.ignore();
                        cout<<"Enter New Department : ";
                        getline(cin,department[i]);
                        break;

                    case 3:
                        cout<<"Enter New Salary : ";
                        cin>>salary[i];

                        while(salary[i]<0){
                            cout<<"Invalid Salary : ";
                            cin>>salary[i];
                        }
                        break;

                    case 4:
                        return;

                    default:
                        cout<<"Invalid Option\n";
                }

            }while(option!=4);
        }
    }

    cout<<"Employee Not Found\n";
}
void removeemployee(){

    int empid;

    cout<<"Enter Employee ID : ";
    cin>>empid;

    for(int i=0;i<id.size();i++){

        if(id[i]==empid){

            id.erase(id.begin()+i);
            name.erase(name.begin()+i);
            department.erase(department.begin()+i);
            salary.erase(salary.begin()+i);

            cout<<"Employee Removed Successfully\n";
            return;
        }
    }

    cout<<"Employee Not Found\n";
}
void incrementsalary(){

    int empid;
    double amount;

    cout<<"Enter Employee ID : ";
    cin>>empid;

    for(int i=0;i<id.size();i++){

        if(id[i]==empid){

            cout<<"Current Salary : "<<salary[i]<<endl;

            cout<<"Increase By : ";
            cin>>amount;

            while(amount<0){
                cout<<"Invalid Amount : ";
                cin>>amount;
            }

            salary[i]+=amount;

            cout<<"New Salary : "<<salary[i]<<endl;
            return;
        }
    }

    cout<<"Employee Not Found\n";
}
void highestsalary(){

    if(id.empty()){
        cout<<"No Employees Found\n";
        return;
    }

    int max=0;

    for(int i=1;i<salary.size();i++){

        if(salary[i]>salary[max])
            max=i;
    }

    cout<<"\nHighest Salary Employee\n";

    cout<<"ID         : "<<id[max]<<endl;
    cout<<"Name       : "<<name[max]<<endl;
    cout<<"Department : "<<department[max]<<endl;
    cout<<"Salary     : "<<salary[max]<<endl;
}
void sortid(){

    for(int i=0;i<id.size()-1;i++){

        for(int j=i+1;j<id.size();j++){

            if(id[i]>id[j]){

                swap(id[i],id[j]);
                swap(name[i],name[j]);
                swap(department[i],department[j]);
                swap(salary[i],salary[j]);
            }
        }
    }

    cout<<"Sorted By ID\n";
}
void sortname(){

    for(int i=0;i<name.size()-1;i++){

        for(int j=i+1;j<name.size();j++){

            string a=name[i];
            string b=name[j];

            transform(a.begin(),a.end(),a.begin(),::tolower);
            transform(b.begin(),b.end(),b.begin(),::tolower);

            if(a>b){

                swap(id[i],id[j]);
                swap(name[i],name[j]);
                swap(department[i],department[j]);
                swap(salary[i],salary[j]);
            }
        }
    }

    cout<<"Sorted By Name\n";
}
