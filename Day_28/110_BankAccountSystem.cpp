//Program to create a bank account system 

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

struct account{
    long long accnum;
    double balance;
    string pin;
};
struct Loan {
    double amount;
    double rate;      
    int years;

    vector<bool> monthlyPaid;

    Loan(double amt, double r, int y)
        : amount(amt),
          rate(r),
          years(y),
          monthlyPaid(y * 12, false)
    {}

    int months() const {
        return years * 12;
    }

    double interest() const {
        return amount * rate * years / 100.0;
    }
};
struct customer{
    string name;
    long long number;
    string address;
    string id;
    account account;
    vector<Loan> loans;
};

void wthdrw(customer &customer);
void deposit(customer &customer);
bool checkpin(string);

void balance(customer &customer);
void loan(customer &customer);
void update(customer &customer);
void newaccount(vector <customer> &accholders);
void oldaccount(vector <customer> &accholders);

int main(){

    vector<customer> accholders;
    int option;
    string bank, branch;
    cout << "Enter Bank Name : ";
    getline(cin, bank);

    cout << "Branch : ";
    getline(cin, branch);

    do{
        cout << "Menu => \n"
        << "1. Open New Account\n"
        << "2. Work with already open account\n"
        << "3. exit\n";
        cin >> option;

        switch(option){
            case 1: newaccount(accholders);
            break;

            case 2: oldaccount(accholders);
            break;

            case 3: cout << "*** THANK YOU ***\n";
            return 0;
        }
    }while(option != 3);
return 0;
}

bool checkpin(string pin){
    
    if(pin.length() != 4)  return false;

    for (char x: pin ) {
        if ( !isdigit(x) )  return false;
    } 

    return true;
}
void wthdrw(customer &customer){
    
    double money;
    string newpin;
    cout << "Enter Amount to withdraw: \nRs. ";
    cin >> money;

    if(money <= 0) {
        cout << "Invalid Withdraw amount\n";
        return;
    }

    if(money > 3000000 || money < 200){ 
        cout << "LIMIT EXCEEDED\n Withdraw Range is from Rs. 200 to Rs. 3000000 at once\n";
        return;
    }

    cout << "Enter PIN : \n";
    cin >> newpin;

    if(newpin != customer.account.pin){
        cout << "INCORRECT PIN\n";
        cout << "Transaction Cancelled\n";
        return;

    }

    if(money > customer.account.balance) {
        cout << "INSUFFICIENT BALANCE\nWithdraw Unsuccessful\n";
        money = 0;
    }
    else
        cout << "Rs. " << money << " succcessfully withdrawn " << endl;

    customer.account.balance -= money;
    cout << "Available Balance : Rs. " << customer.account.balance << endl;
    return ;
}
void deposit(customer &customer){

    double money;
    cout << "Enter Amount to deposit: \nRs. ";
    cin >> money;

    if(money <= 0) {
        cout << "Invalid Deposit amount\n";
        return;
    }

    if(money > 5000000 || money < 50){ 
        cout << "LIMIT EXCEEDED\n Deposit Range is from Rs. 50 to Rs. 5000000\n";
        money = 0;
    }
    else
        cout << "Succcessfully deposited " << "Rs. " << money << endl;

    customer.account.balance+=money;
    cout << "Available Balance : Rs. " << customer.account.balance << endl;
    return;
}

void balance(customer &customer){

    cout << "Current balance = " << customer.account.balance << endl;
}
void loan(customer &customer){

    int option;

    do{
        cout << "Loan => \n"
        << "1. Pending Loans\n"
        << "2. Apply for new loan\n"
        << "3. Pay Monthly Installment\n"
        << "4. Exit\n";

        cin >> option;

        switch(option){
            case 1:{
                if(customer.loans.empty()){
                    cout << "No Active Loans\n";
                    break;
                }

                for(int i=0; i<customer.loans.size(); i++){

                    Loan &l = customer.loans[i];
                    int paid = count(l.monthlyPaid.begin(), l.monthlyPaid.end(), true);

                    cout << i+1 << ". Loan Amount : Rs. "
                    << l.amount
                    << "\n   Interest Rate : "
                    << l.rate << "%"
                    << "\n   Duration : "
                    << l.years << " years"
                    << "\n   Total Interest : Rs. "
                    << l.interest()
                    << "\n   Months Paid : "
                    << paid << "/" << l.months()
                    << "\n\n";
                }
                break;
            }

            case 2:{
                double amount, rate;
                int years;

                cout << "Enter Loan Amount : Rs. ";
                cin >> amount;
                cout << "Enter Interest Rate (%): ";
                cin >> rate;
                cout << "Enter Duration (Years): ";
                cin >> years;

                Loan newloan(amount, rate, years);

                customer.loans.push_back(newloan);

                cout << "Loan Approved\n";
                cout << "Amount Credited : Rs. " << amount << endl;

                customer.account.balance += amount;

                cout << "Available Balance : Rs. " << customer.account.balance << endl;

                break;
            }

            case 3:{
                if(customer.loans.empty()){
                    cout << "No Active Loans\n";
                    break;
                }

                int loanno;
                cout << "Select Loan\n";

                for(int i=0; i<customer.loans.size(); i++){
                    cout << i+1
                        << ". Rs. "
                        << customer.loans[i].amount
                        << endl;
                }
                cin >> loanno;

                if(loanno < 1 ||
                   loanno > customer.loans.size()){
                    cout << "Invalid Option\n";
                    break;
                }

                Loan &l = customer.loans[loanno-1];

                int month = -1;

                for(int i=0; i<l.monthlyPaid.size(); i++){
                    if(!l.monthlyPaid[i]){
                        month = i;
                        break;
                    }
                }

                if(month == -1){
                    cout << "Loan Already Cleared\n";
                    break;
                }

                double monthlyAmount =
                (l.amount + l.interest()) / l.months();

                if(customer.account.balance <
                   monthlyAmount){

                    cout << "Insufficient Balance\n";
                    break;
                }

                customer.account.balance -= monthlyAmount;

                l.monthlyPaid[month] = true;

                cout << "Installment Paid : Rs. "
                     << monthlyAmount << endl;

                cout << "Remaining Balance : Rs. "
                     << customer.account.balance
                     << endl;

                break;
            }

            case 4:
                return;

            default : cout << "Choose from options\n";
        }

    }while(option != 4);
}
void update(customer &customer){
    
    int option, otp;
    long long number;
    string address;
    
    cout << "Update ? \n"
    << "1. Phone number\n"
    << "2. Address\n"
    << "3. exit\n";
    cin >> option;

    switch(option){
        case 1 : cout << "Phone number : " << customer.number << endl;
        cout << "Enter new number : ";
        cin >> number;
        cout << "Enter otp : ";
        cin >> otp;
        cout << "Number updated successfully\n";
        customer.number = number;
        break;

        case 2 : cout << "Address : " << customer.address << endl;
        cout << "Enter new address : ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter otp : ";
        cin >> otp;
        cout << "Address updated successfully\n";
        customer.address = address;
        break;

        case 3 : return;

        default : cout << "Invalid Input\n";
    }
} 
void newaccount(vector <customer> &accholders){
    
    customer newholder;
    
    cin.ignore();
    cout << "Enter your Name : ";
    getline(cin, newholder.name);
    cout << "Enter your ID number : ";
    getline(cin, newholder.id);
    cout << "Enter your Address : ";
    getline(cin, newholder.address);
    cout << "Enter your phone number : ";
    cin >> newholder.number;
    cout << "Account created\nYour account number is : ";
    newholder.account.accnum = (rand()%(25110318180000-25110318120000))+25110318180000;
    cout << newholder.account.accnum;
    do{
        cout << "\nAdd PIN for further usage : ";
        cin >> newholder.account.pin;
        if(!checkpin(newholder.account.pin)){
            cout << "Create valid pin\n";
        }
    }while(!checkpin(newholder.account.pin));

    cout << "Deposit your first amount : ";
    cin >> newholder.account.balance;

    cout << "ALL SET...\n";
    accholders.push_back(newholder);
}
void oldaccount(vector <customer> &accholders){

    int option, index;
    long long accnum, number;
    string name;
    bool found = false;

    do{
        cout << "Enter account number : \n";
        cin >> accnum;
        if(accnum==-1) return;
        cout << "Enter Account Holders Name : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter phone number : ";
        cin >> number;

        for(int x=0; x<accholders.size(); x++){
            if (accholders[x].account.accnum == accnum  &&  accholders[x].name == name  &&  accholders[x].number == number){
                cout << "Account found\n";   
                found = true;  
                index = x;
                break;       
            }
            else found = false;
        }

        if(!found) cout << "Wrong credentials entered\nPress '-1' to exit\n";
    }while(!found);

    do{
        cout << "Menu => \n"
        << "1. Check Balance\n"
        << "2. Deposit\n"
        << "3. Withdraw\n"
        << "4. Help with Loan\n"
        << "5. Update account info\n"
        << "6. Exit\n";

        cin >> option;

        switch(option){
            case 1 : balance(accholders[index]);
            break;
            case 2 : deposit(accholders[index]);
            break;
            case 3 : wthdrw(accholders[index]);
            break;
            case 4 : loan(accholders[index]);
            break;
            case 5 : update(accholders[index]);
            break;
            case 6 : 
            return;
            default : cout << "Choose from options\n";
            
        }
    }while(option != 6);
}
