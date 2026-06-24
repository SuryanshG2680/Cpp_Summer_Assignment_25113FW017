//Program to Create ATM simulation

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

double wthdrw(double, string);
double deposit(double);
bool checkpin(string);
bool checkaccount(string);

int main(){

    string accnum;
    double balance;
    int option;
    string pin;

    cout << "Enter Account Number : ";
    cin >> accnum;
    
    if(!checkaccount(accnum)){
        cout << "Invalid Account number";
        return 0;
    }

    balance = 10000.00;
    cout << "Enter 4 digit PIN : ";
    cin >> pin;

    if(!checkpin(pin)) {
        cout << "INVALID PIN\n";
        return 0;
    }

    cout << "Details Fetched Successfully\n";
    cout << "Account Balance = Rs. " << balance << endl; 

  /* 
    do{
        cout << "Enter Account Balance : " ;
        cin >> balance ;
        if(balance < 0)
            cout << "Invalid Balance \n";

    }while(balance < 0);
*/
    do{
        cout << "*******************************\n";
        cout << "Choose an option to continue-" << endl;
        cout << "1 > Check Balance \n";
        cout << "2 > Withdraw Money \n";
        cout << "3 > Deposit Money \n";
        cout << "4 > Exit \n"; 
        cin >> option ;

        switch(option){
            case 1 :  {
                cout << "Your current account balance is : Rs. " << balance << endl;
                break;
            }
            case 2 :  {
                balance = wthdrw(balance, pin);
                break;
            }
            case 3 :  {
                balance = deposit(balance);
                break;
            }
            case 4 :  {
                cout << "Thankyou for visiting" << endl;
                break;
            }
            default :  {
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

    }while(option != 4);

    return 0;
    
}

bool checkaccount(string acc){
    
    for(char x : acc)
        if(!isalnum(x)) return false;

    if (acc.length() < 10 || acc.length() > 15) return false;

    return true;

}
bool checkpin(string pin){
    
    if(pin.length() != 4)  return false;

    for (char x: pin ) {
        if ( !isdigit(x) )  return false;
    } 

    return true;
}
double wthdrw(double amt, string pin){
    
    double money;
    string newpin;
    cout << "Enter Amount to withdraw: \nRs. ";
    cin >> money;

    if(money <= 0) {
        cout << "Invalid Withdraw amount\n";
        return amt;
    }

    if(money > 300000 || money < 200){ 
        cout << "LIMIT EXCEEDED\n Withdraw Range is from Rs. 200 to Rs. 300000 at once\n";
        return amt;
    }

    cout << "Enter PIN : \n";
    cin >> newpin;

    if(newpin != pin){
        cout << "INCORRECT PIN\n";
        cout << "Transaction Cancelled\n";
        return amt;

    }

    if(money>amt) {
        cout << "INSUFFICIENT BALANCE\nWithdraw Unsuccessful\n";
        money = 0;
    }
    else
        cout << "Rs. " << money << " succcessfully withdrawn " << endl;

    cout << "Available Balance : Rs. " << amt-money << endl;
    return amt-=money;
}
double deposit(double amt){

    double money;
    cout << "Enter Amount to deposit: \nRs. ";
    cin >> money;

    if(money <= 0) {
        cout << "Invalid Deposit amount\n";
        return amt;
    }

    if(money > 500000 || money < 50){ 
        cout << "LIMIT EXCEEDED\n Deposit Range is from Rs. 50 to Rs. 500000\n";
        money = 0;
    }
    else
        cout << "Succcessfully deposited " << "Rs. " << money << endl;

    cout << "Available Balance : Rs. " << amt+money << endl;
    return amt+=money;
}
