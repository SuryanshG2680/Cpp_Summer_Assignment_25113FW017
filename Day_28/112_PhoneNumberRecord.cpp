//Program to Create contact management system
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

struct add{
    
    string housenum;
    string colony;
    string area;
    string city;
    void print() const{
        cout << housenum << " , " 
            << colony << " , "
            << area << " , "
            << city << " ";
    }
};
struct contactlist{

    string number;
    string name;
    string nickname;
    string relation;
    add address;
};

void result(const vector<int> &index, const vector <contactlist> &mycontact);
void printcontact(const contactlist &contact);
void Sorting(vector<contactlist> &mycontact);
void DeleteContact(vector<contactlist> &mycontact);
void ModifyContact(vector<contactlist> &mycontact);
void SearchContact(const vector<contactlist> &mycontact);
void Display(const vector<contactlist> &mycontact);
void addcontact(vector <contactlist> &contact);

bool cmpname( contactlist const &a, contactlist const &b){
    return a.name < b.name;
}
bool cmpnumber( contactlist const &a, contactlist const &b){
    return stoll(a.number) < stoll(b.number);
}

int main(){
    
    char yesno;
    int option;
    vector<contactlist> mycontactlist;

    do{
        cout << "Add Contact ? (y/n) ";
        cin >> yesno; 
        if( yesno=='y' || yesno=='Y') {
           addcontact(mycontactlist);
        }
        else if( yesno=='N' || yesno=='n') {
            break;
        }
        else{
            cout << "Enter valid response\n";
        }
    }while ( yesno!='y' && yesno!='Y' && yesno!='N' && yesno!='n');

    do{
        cout << "MENU => \n";
        cout << "1. Display All Contacts \n"
            << "2. Search contact\n"
            << "3. Add Contact\n"
            << "4. Delete Contact\n"
            << "5. Sort\n"
            << "6. Modify contact details\n"
            << "7. Exit\n";
        cin >> option;

        switch(option){
            case 1 : Display(mycontactlist);
                    break;
            case 2 : SearchContact(mycontactlist);
                    break;
            case 3 : addcontact(mycontactlist);
                    break;
            case 4 : DeleteContact(mycontactlist);
                    break;
            case 5 : Sorting(mycontactlist);
                    break;
            case 6 : ModifyContact(mycontactlist);
                    break;
            case 7 : cout << "*** THANK YOU ***\n";
                    return 0;
            default : cout << "Enter valid input\n";
        }

    }while(option != 7);

    return 0;
}

void printcontact(const contactlist &contact){

    cout << "\tNmae : " << contact.name;
    if(contact.nickname.length() != 0){
        cout << "\n\tNickname : " << contact.nickname;
    }
    cout << "\n\tPhone Number : " << contact.number;
    cout << "\n\tRelation : " << contact.relation;
    cout << "\n\tAddress : ";
    contact.address.print();
    cout << "\n";

}
void Sorting(vector<contactlist> &mycontact){

    int option;
    cout << "SORT BY ? \n" << "1. Name\n" << "2. Phone Number\n";
    cin >> option;

    switch(option){
        case 1 : sort(mycontact.begin(), mycontact.end(), cmpname);
                break;
        case 2 : sort(mycontact.begin(), mycontact.end(), cmpnumber);
                break;
        
        default : break;
    }
}
void DeleteContact(vector<contactlist> &mycontact){
    
    int option, i;
    char yesno;
    bool found=false;
    string search;
    do{
        cout << "Search by \n1. Name or\n2. Number\nto delete?\n";
        cin >> option;
    
        if(option != 1 && option != 2) cout << "Choose from options\n";    
    }while(option != 1 && option != 2);

    cin.ignore();
    if(option == 1){
        cout << "Enter name : ";
        getline(cin, search);

        for(i=0; i<mycontact.size(); i++){
            if(search == mycontact[i].name){
                found=true;
                printcontact(mycontact[i]);
                cout << "\n";
                break;
            }
        }
    }

    if(option == 2){
        cout << "Enter Phone Number : ";
        do{
            getline(cin, search);
    
            if(search.length() != 10 || !all_of(search.begin(), search.end(), ::isdigit))
                cout << "Enter valid number\n";

        }while( search.length() != 10 || !all_of(search.begin(), search.end(), ::isdigit));

        for(i=0; i<mycontact.size(); i++){
            if(search == mycontact[i].number){
                found=true;
                printcontact(mycontact[i]);
                cout << "\n";
                break;
            }
        }
    }

    if(!found){
        cout << "Contact Not Found\n";
        return;
    }
    do{
        cout << "Delete this contact? (y/n) ";
        cin >> yesno; 
        if( yesno=='y' || yesno=='Y') {
           mycontact.erase(mycontact.begin()+ i);
        }
        else if( yesno=='N' || yesno=='n') {
            break;
        }
        else{
            cout << "Enter valid response\n";
        }
    }while ( yesno!='y' && yesno!='Y' && yesno!='N' && yesno!='n');
    return;
};
void ModifyContact(vector<contactlist> &mycontact){

    int option, i;
    char yesno;
    bool found=false;
    string search;
    do{
        cout << "Search by \n1. Name or\n2. Number\nto delete?\n";
        cin >> option;
    
        if(option != 1 && option != 2) cout << "Choose from options\n";    
    }while(option != 1 && option != 2);

    cin.ignore();
    if(option == 1){
        cout << "Enter name : ";
        getline(cin, search);

        for(i=0; i<mycontact.size(); i++){
            if(search == mycontact[i].name){
                found=true;
                printcontact(mycontact[i]);
                cout << "\n\n";
                break;
            }
        }
    }

    if(option == 2){
        cout << "Enter Phone Number : ";
        do{
            getline(cin, search);
    
            if(search.length() != 10 || !all_of(search.begin(), search.end(), ::isdigit))
                cout << "Enter valid number\n";

        }while( search.length() != 10 || !all_of(search.begin(), search.end(), ::isdigit));

        for(i=0; i<mycontact.size(); i++){
            if(search == mycontact[i].number){
                found=true;
                printcontact(mycontact[i]);
                cout << "\n\n";
                break;
            }
        }
    }

    if(!found){
        cout << "Contact Not Found\n";
        return;
    }
    do{
        cout << "Choose what to modify in this contact card ?\n"
            << "1. Name\n"
            << "2. Contact Number\n"
            << "3. Nickname\n"
            << "4. Relation\n"
            << "5. Address\n";
        cin >> option ; 

    string temp;
    switch(option){
        case 1 : cout << "New Name : ";
                cin.ignore();
                getline(cin, temp);
                if(mycontact[i].name == temp){
                    cout << "No change Made\n";
                };
                mycontact[i].name = temp;
                break;

        case 2 : do{
                    cout << "New Phone Number : ";
                    cin.ignore();
                    getline(cin, temp);
            
                    if(temp.length() != 10 || !all_of(temp.begin(), temp.end(), ::isdigit)){
                        cout << "Enter valid number\n";
                    }
                }while( temp.length() != 10 || !all_of(temp.begin(), temp.end(), ::isdigit));
                if(mycontact[i].number == temp){
                    cout << "No change Made\n";
                };
                mycontact[i].number = temp;
                break;
        
        case 3 : cout << "Nickname : ";
                cin.ignore();
                getline(cin, temp);
                if(mycontact[i].nickname == temp){
                    cout << "No change Made\n";
                };
                mycontact[i].nickname = temp;
                break;

        case 4 : cout << "New Relation : ";
                cin.ignore();
                getline(cin, temp);
                if(mycontact[i].relation == temp){
                    cout << "No change Made\n";
                };
                mycontact[i].relation = temp;
                break;

        case 5 : cout << "New Address : \n";
                cin.ignore();
                cout << "House Number : ";
                getline(cin, mycontact[i].address.housenum);
                cout << "Colony : ";
                getline(cin, mycontact[i].address.colony);
                cout << "Area : ";
                getline(cin, mycontact[i].address.area);
                cout << "City : ";
                getline(cin, mycontact[i].address.city);
                cout << "New Address => ";
                mycontact[i].address.print();
                cout << endl;
                break;                
        
        default : cout << "Choose from options\n";
        }

    }while ( option > 5 || option < 1);

    return;
};
void SearchContact(const vector<contactlist> &mycontact){

    int option, addressoption;
    do{
        vector<int> index;
        cout << "Search by : \n1. Name\n2. Number\n3. Nickname\n4. Address\n5. Back\n";
        cin >> option;
    
        switch (option){
            case 1 : {
                    string search;
                    cout << "Enter Name : ";
                    cin.ignore();
                    getline(cin, search);
                    for(int i=0; i<mycontact.size() ; i++){
                        if(mycontact[i].name.find(search) < mycontact[i].name.size()) index.push_back(i);
                    }
                }
                result(index, mycontact);
                break;
    
            case 2 : {
                    string number;
                    do{
                        cout << "Enter number : ";
                        cin >> number;
                        if(number.length() != 10 || !all_of(number.begin(), number.end(), ::isdigit)){
                            cout << "Enter valid number\n";
                        }
                    }while( number.length() != 10 || !all_of( number.begin(), number.end(), ::isdigit));
    
                    for(int i=0; i<mycontact.size() ; i++){
                        if(number == mycontact[i].number) index.push_back(i);
                    }
                }
                result(index, mycontact);
                break;
    
            case 3 : {
                    string nickname;
                    cout << "Enter Nickname : ";
                    cin.ignore();
                    getline(cin, nickname);
                    for(int i=0; i<mycontact.size() ; i++){
                        if(mycontact[i].nickname.find(nickname) < mycontact[i].nickname.size()) index.push_back(i);
                    }
                }
                result(index, mycontact);
                break;
    
            case 4 : do{
                        cout << "ADDRESS SORT :\n1. House Number\n2. Colony\n3. Area\n4. City\n5. Back";
                        cin >> addressoption;
                        switch (addressoption){
                            case 1 : {
                                    string add;
                                    cout << "Enter House Number : ";
                                    cin.ignore();
                                    getline(cin, add);
                                    for(int i=0; i<mycontact.size() ; i++){
                                        if(add == mycontact[i].address.housenum) index.push_back(i);
                                    }
                                }
                                result(index, mycontact);
                                break;
                            case 2 : {
                                    string add;
                                    cout << "Enter Colony : ";
                                    cin.ignore();
                                    getline(cin, add);
                                    for(int i=0; i<mycontact.size() ; i++){
                                        if(add == mycontact[i].address.colony) index.push_back(i);
                                    }
                                }
                                result(index, mycontact);
                                break;
                            case 3 : {
                                    string add;
                                    cout << "Enter Area : ";
                                    cin.ignore();
                                    getline(cin, add);
                                    for(int i=0; i<mycontact.size() ; i++){
                                        if(add == mycontact[i].address.area) index.push_back(i);
                                    }
                                }
                                result(index, mycontact);
                                break;
                            case 4 : {
                                    string add;
                                    cout << "Enter City : ";
                                    cin.ignore();
                                    getline(cin, add);
                                    for(int i=0; i<mycontact.size() ; i++){
                                        if(add == mycontact[i].address.city) index.push_back(i);
                                    }
                                }
                                result(index, mycontact);
                                break;
    
                            case 5 : break;
                            default : cout << "Choose from options\n";
                        }
                    }while(addressoption != 5);
                    break;
            case 5 : return;
    
            default : cout << "Choose from options \n";
        }           
    } while (option != 5);
};
void Display(const vector<contactlist> &mycontact){

    if(mycontact.empty()) {
        cout << "No Contacts added yet\n";
        return;
    }
    for(int i =0; i< mycontact.size(); i++){
        cout << i+1 << ". \t";
        printcontact(mycontact[i]);
    }
};
void addcontact(vector <contactlist> &contact){
        
        string save;
        contactlist newcontact;
        char yesno;
    
        cout << "Name : ";
        cin.ignore();
        getline(cin, newcontact.name);
        
        do{
            cout << "Phone Number : ";
            getline(cin, newcontact.number);
    
            if(newcontact.number.length() != 10 || !all_of(newcontact.number.begin(), newcontact.number.end(), ::isdigit)){
                cout << "Enter valid number\n";
            }
        }while( newcontact.number.length() != 10 || !all_of(newcontact.number.begin(), newcontact.number.end(), ::isdigit));
    
        cout << "Relation : ";
        getline(cin, newcontact.relation);
        cout << "Address : \n";
        cout << "House Number : ";
        getline(cin, newcontact.address.housenum);
        cout << "Colony : ";
        getline(cin, newcontact.address.colony);
        cout << "Area : ";
        getline(cin, newcontact.address.area);
        cout << "City : ";
        getline(cin, newcontact.address.city);
        cout << "Address => ";
        newcontact.address.print();
        cout << endl;
        
        cout << "Nickname ? (y/n) ";
        do{
            cin >> yesno; 
            if( yesno=='y' || yesno=='Y') {
                cout << "Enter Name : ";
                cin.ignore();
                getline(cin, newcontact.nickname);
                break;
            }
            else if( yesno=='N' || yesno=='n') {

                newcontact.nickname = "";
                break;
            }
            else{
                cout << "Enter valid response\n";
            }
        }while ( yesno!='y' && yesno!='Y' && yesno!='N' && yesno!='n');
    
        cout << "Press Enter to save this contact or 'B' to go back without saving \n";
        cin.ignore();
        getline(cin, save);
        if(save[0] == 'b' || save[0] == 'B'){
            return;
        }
        contact.push_back(newcontact);
        return;
    
    }
// for search 
void result(const vector<int> &index, const vector <contactlist> &mycontact){
    if(index.empty()){
    cout << "No Record Found\n";
    }
        
    else{
        cout << "Search Result => \n";
        for(int i=0; i < index.size(); i++){
            cout << i+1 << ". ";
            printcontact(mycontact[index[i]]);
        }
    }
};