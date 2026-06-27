//Program to Create menu-driven calculator
 
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void add(){
    
    string num="0";
    float sum=0;
    cout << "Enter number and press enter to add or = to end adding numbers\n";
    cin.ignore();
    do{
        getline(cin, num);
        if(num == "=" || num == "") break;
        try {
            sum += stof(num);
        }
        catch (invalid_argument&) {
            cout << "Invalid number. Try again.\n";
            continue;          
        }

        cout << "\t= " << sum << "\n+ ";

    }while(num != "=");
    cout << "Sum = " << sum << endl;
};
void subtract(){
    string num="0";
    float sum=0;
    cout << "Enter number and press enter to subtract or = to end adding numbers\n";
    cin.ignore();
    getline(cin, num);
    sum = stof(num);
    do{
        cout << "\t= " << sum << "\n- ";
        getline(cin, num);
        if(num == "=" || num == "") break;
        try {
            sum -= stof(num);
        }
        catch (invalid_argument&) {
            cout << "Invalid number. Try again.\n";
            continue;          
        }

    }while(num != "=");
    cout << "Answer = " << sum << endl;
};
void multiply(){
    string num="0";
    long double prod=1;
    cout << "Enter number and press enter to subtract or = to end adding numbers\n";
    cin.ignore();
    do{
        getline(cin, num);
        if(num == "=" || num == "") break;
        try {
            prod *= stof(num);
        }
        catch (invalid_argument&) {
            cout << "Invalid number. Try again.\n";
            continue;          
        }
        cout << "\t= " << prod << "\n* ";

    }while(num != "=");
    cout << "\rProduct = " << prod << endl;
};
void divide(){
    string num;
    long double result;

    while(true){
        cout << "Enter first number\n";
        cin.ignore();
    
        getline(cin, num);
        try{
            result = stold(num);
            break;
        }
        catch (invalid_argument&) {
            cout << "Invalid number. Try again.\n";
            continue;          
        }
    }

    while (true) {
        cout << "\t= " << result << "\n/ ";
        getline(cin, num);

        if (num == "=" || num == "")  break;

        try{
            long double divisor = stold(num);
            if (divisor == 0) {
                cout << "Cannot divide by zero\n";
                continue;
            }
            result /= divisor;    
        }
        catch (invalid_argument&) {
            cout << "Invalid number. Try again.\n";
            continue;          
        }
    }

    cout << "Answer = " << result << endl;
}

int main(){

    int option;
    cout << "*** CALCULATOR ***\n";
    do{
        
        cout << "\nMENU =>\n"
            << "1. Add\n"
            << "2. Subtract\n"
            << "3. Multiply\n"
            << "4. Divide\n"
            << "5. Exit\n";
        cin >> option;
    
        switch(option){
            case 1 : add();
                    break;
            case 2 : subtract();
                    break;
            case 3 : multiply();
                    break;
            case 4 : divide();
                    break;
            case 5 : cout << "*** THANK YOU ***\n";
                    return 0;
            default : cout << "Choose from given operations to perform\n";
        }
    }while(option != 5);

    return 0;
}