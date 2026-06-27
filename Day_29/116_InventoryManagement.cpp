//Program to Create inventory management system
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

struct STOCKS {

    int id;
    string name;
    string company;
    int quantity;
    double cp;
    double sp;
    double profit(){
        return sp-cp;
    }
    double total(){
        return profit()*quantity;
    }
};

bool cmpid(const STOCKS &a, const STOCKS &b){
    return a.id < b.id;
}
bool cmpname(const STOCKS &a, const STOCKS &b){
    return a.name < b.name;
}
bool cmpcompany(const STOCKS &a, const STOCKS &b){
    return a.company < b.company;
}

void printproduct( const STOCKS &product);

void add(vector<STOCKS> &product);
void display(vector<STOCKS> &product);
void remove( vector<STOCKS> &product);
void sell(vector<STOCKS> &product);
void update(vector<STOCKS> &product);
void restock(vector<STOCKS> &product);
void sorting(vector<STOCKS> &product);
void search(const vector<STOCKS> &product);

int main(){

    vector<STOCKS> product;
    int number, option;

    
    cout << "****  INVENTORY MANAGEMENT  ****\n";
    cout << "Enter initial number of products to add in the inventory : ";
    cin >> number;
    for(int i=0; i< number; i++){
        add(product); 
    }
    do{
        cout << "MENU => \n"
        << "1. Add Product\n"
        << "2. Remove Product\n"
        << "3. Search Product\n"
        << "4. Update Product\n"
        << "5. Sell Product\n"
        << "6. Restock Product\n"
        << "7. Display Inventory\n"
        << "8. Sort Products\n"
        << "9. Exit\n";
        
        cin >> option;
        switch(option){
            case 1 : add(product);
                   break;
            case 2 : remove(product);
                   break;
            case 3 : search(product);
                   break;
            case 4 : update(product);
                   break;
            case 5 : sell(product);
                   break;
            case 6 : restock(product);
                   break;
            case 7 : display(product);
                   break;
            case 8 : sorting(product);
                   break;
            case 9 : cout << "*** THANK YOU ***\n";
                   return 0;
            default : cout << "Choose from options\n";
        }
    }while(option != 9);

    return 0;
}

void printproduct( const STOCKS &product){
    STOCKS prod=product;
    if(!prod.name.empty()){
        prod.name[0] = toupper(prod.name[0]);
    }
    cout << "  Product NAME : " << prod.name
            << "\n\tCompany       : " << prod.company
            << "\n\tProduct ID    : " << prod.id
            << "\n\tQuantity Left : " << prod.quantity
            << "\n\tSell Price    : " << prod.sp << endl;
}
void add(vector<STOCKS> &product){
    
    bool alreadyexist;
    char yesno;
    STOCKS newproduct;
    cout << "Enter Details : \n";
    cout << "Product Name : ";
    cin.ignore();
    getline(cin, newproduct.name);
    do{
        alreadyexist = false;
        cout << "ID : ";
        cin >> newproduct.id;
        for(auto &x : product){
            if(x.id == newproduct.id){
                cout << "ID already exists\n";
                alreadyexist = true;
            }
        }
    }while(alreadyexist);
    cout << "Company : ";
    cin.ignore();
    getline(cin, newproduct.company);
    do{
        cout << "Quantity : ";
        cin >> newproduct.quantity;
        if(newproduct.quantity < 0){
            cout << "Quantity cannot be less than zero\n";
            continue;
        }
    }while(newproduct.quantity < 0);
    cout << "Cost Price : ";
    cin >> newproduct.cp;
    cout << "Sell Price : ";
    cin >> newproduct.sp;

    cout << "Add this Product ? (y/n) ";
    cin >> yesno;
    if(toupper(yesno) == 'N'){
        cout << "Product dismissed\n";
        return;
    }
    else{
        product.push_back(newproduct);
        cout << "Product Added\n";
    }
    return;
};
void display(vector<STOCKS> &product){
    
    for(int i=0; i< product.size() ; i++){
        cout << i+1 << ". ";
        printproduct(product[i]);
        cout << "\tCost Price    : " << product[i].cp << endl;
        cout << "\tProfit        : " << product[i].profit() << endl;
        cout << "\tTotal Stock Value : " << product[i].total() << endl;
        if(product[i].quantity <= 5) cout << "      *** ONLY " << product[i].quantity << " REMAINING\n";
    }
};
void remove( vector<STOCKS> &product){
    
    string find;
    vector<int> index;
    int option ;
    bool found=false;
    cin.ignore();
    cout << "Enter ID or Product name to find : ";
    getline(cin, find);

    if(all_of(find.begin(), find.end(), ::isdigit)){
        
        for(int i=0; i<product.size(); i++){
            string id = to_string(product[i].id);
            if( id.find(find) != string::npos){
                index.push_back(i);
                found=true;
            }
        }
    }
    else{
        transform(find.begin(), find.end(), find.begin(), ::tolower);
        for(int i=0; i<product.size(); i++){
            
            string name=product[i].name;
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            if( name.find(find) != string::npos){
                index.push_back(i);
                found = true;
            }
        }
    }
    if(!found){
        cout << "Product not found\n";
        return;
    }
    for(int i=0; i<index.size(); i++){
        cout << i+1 << ". ";
        printproduct(product[index[i]]);
    }
    
    do{
        cout << "Enter option to remove product : ";
        cin >> option;

    }while(option < 1 || option > index.size());
    
    product.erase(product.begin() + index[option - 1]);
    cout << "Product removed successfully\n";
    return ;

};
void sell(vector<STOCKS> &product){
    string find;
    vector<int> index;
    int option, sell ;
    bool found=false;
    cin.ignore();
    cout << "Enter ID or Product name to find : ";
    getline(cin, find);

    if(all_of(find.begin(), find.end(), ::isdigit)){
        for(int i=0; i<product.size(); i++){
             string id = to_string(product[i].id);
            if( id.find(find) != string::npos){
                index.push_back(i);
                found=true;
            }
        }
    }
    else{
        transform(find.begin(), find.end(), find.begin(), ::tolower);
        for(int i=0; i<product.size(); i++){
            
            string name=product[i].name;
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            if( name.find(find) != string::npos){
                index.push_back(i);
                found = true;
            }
        }
    }

    if(!found){
        cout << "Product not found\n";
        return;
    }

    for(int i=0; i<index.size(); i++){
        cout << i+1 << ". ";
        printproduct(product[index[i]]);
    }

    do{
        cout << "Enter option to sell product : ";
        cin >> option;

    }while(option < 1 || option > index.size());

    do{
        cout << "Current quantity = " << product[index[option-1]].quantity << endl;
        cout << "Enter quantity to sell : ";
        cin >> sell;
        if(product[index[option-1]].quantity < sell){
            cout << "Quantity Remaining is less than selling quantity \n";
            continue; 
        }
        if(sell < 0){
            cout << "Selling quantity cannot be less than zero\n";
            continue;
        }
    }while(sell > product[index[option-1]].quantity || sell < 0);
    
    product[index[option-1]].quantity -= sell;
    cout << "New Quantity = " << product[index[option-1]].quantity << endl;
    if(product[index[option-1]].quantity <= 5) cout << "   *** ONLY " << product[index[option-1]].quantity << " REMAINING\n";

    return;
};
void update(vector<STOCKS> &product){
    
    string find, update;
    vector<int> index;
    int option, option2 ;
    bool found=false;

    cin.ignore();
    cout << "Enter ID or Product name to find : ";
    getline(cin, find);
    
    
    if(all_of(find.begin(), find.end(), ::isdigit)){
        for(int i=0; i<product.size(); i++){

            string id = to_string(product[i].id);
            if( id.find(find) != string::npos){
                index.push_back(i);
                found=true;
            }
        }
    }
    else{
        transform(find.begin(), find.end(), find.begin(), ::tolower);
        for(int i=0; i<product.size(); i++){
            
            string name=product[i].name;
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            if( name.find(find) != string::npos){
                index.push_back(i);
                found = true;
            }
        }
    }
    
    
    if(!found){
        cout << "Product not found\n";
        return;
    }

    for(int i=0; i<index.size(); i++){
        cout << i+1 << ". ";
        printproduct(product[index[i]]);
        cout << "\tCost Price    : " << product[index[i]].cp << endl;
    }

    do{
        cout << "Enter option to update product : ";
        cin >> option;
        
    }while(option < 1 || option > index.size());
    
    do{
        cout << "Update =>\n"
            << "1. ID\n"
            << "2. Name\n"
            << "3. Company\n"
            << "4. Quantity\n"
            << "5. Sell Price\n"
            << "6. Cost Price\n"
            << "7. None\n";
            cin >> option2;
            
        bool alreadyexist = false;
        switch(option2){
            case 1 : do{
                        alreadyexist = false;
                        cout << "ID : ";
                        cin >> product[index[option-1]].id;
                        for(auto &x : product){
                            if(x.id == product[index[option-1]].id){
                                
                                cout << "ID already exists\n";
                                alreadyexist = true;
                            }
                        }
                    }while(alreadyexist);
                    break;
            case 2 : cout << "Enter new Name : ";
                    cin.ignore();
                    getline(cin, product[index[option-1]].name);
                    break;
            case 3 : cout << "Enter new Company : ";
                    cin.ignore();
                    getline(cin, product[index[option-1]].company);
                    break;
            case 4 : do{
                        cout << "Enter new quantity : ";
                        cin >> product[index[option-1]].quantity;
                    }while(product[index[option-1]].quantity < 0);
                    break;
            case 5 : do{
                        cout << "Enter new Sell Price : ";
                        cin >> product[index[option-1]].sp;
                    }while(product[index[option-1]].sp < 0);
                    break;
            case 6 : do{
                        cout << "Enter new Cost Price : ";
                        cin >> product[index[option-1]].cp;
                    }while(product[index[option-1]].cp < 0);
                    break;
            case 7 : return;
            default : cout << "Choose from options\n";
        }
    }while(option2 != 7);
    
    cout << "New Description :\n ";
    printproduct(product[index[option-1]]);
    if(product[index[option-1]].quantity <= 5) cout << "   *** ONLY " << product[index[option-1]].quantity << " REMAINING\n";

    return;
};
void restock(vector<STOCKS> &product){
    
    string find;
    vector<int> index;
    int option, restock ;
    bool found=false;
    cin.ignore();
    cout << "Enter ID or Product name to find : ";
    getline(cin, find);

    if(all_of(find.begin(), find.end(), ::isdigit)){
        for(int i=0; i<product.size(); i++){
             string id = to_string(product[i].id);
            if( id.find(find) != string::npos){
                index.push_back(i);
                found=true;
            }
        }
    }
    else{
        transform(find.begin(), find.end(), find.begin(), ::tolower);
        for(int i=0; i<product.size(); i++){
            
            string name=product[i].name;
            transform(name.begin(), name.end(), name.begin(), ::tolower);
            if( name.find(find) != string::npos){
                index.push_back(i);
                found = true;
            }
        }
    }

    if(!found){
        cout << "Product not found\n";
        return;
    }

    for(int i=0; i<index.size(); i++){
        cout << i+1 << ". ";
        printproduct(product[index[i]]);
    }

    do{
        cout << "Enter option to restock product : ";
        cin >> option;

    }while(option < 1 || option > index.size());

    do{
        cout << "Current quantity = " << product[index[option-1]].quantity << endl;
        cout << "Enter quantity to restock : ";
        cin >> restock;

        if(restock < 0){
            cout << "Quantity cannot be less than zero\n";
            continue;
        }
    }while (restock < 0);
    
    product[index[option-1]].quantity += restock;
    cout << "+" << restock << endl;
    cout << "New Quantity = " << product[index[option-1]].quantity << endl;
    if(product[index[option-1]].quantity <= 5) cout << "   *** ONLY " << product[index[option-1]].quantity << " REMAINING\n";

    return;
};
void sorting(vector<STOCKS> &product){
    int option;
    do{
        cout << "Sort by =>\n"
            << "1. ID\n"
            << "2. Name\n"
            << "3. Company\n"
            << "4. None\n";
        cin >> option;

        switch(option){
            case 1 : sort(product.begin(), product.end(), cmpid);
                    cout << "***** Sorting by ID Done \n";
                    break;
            case 2 : sort(product.begin(), product.end(), cmpname);
                    cout << "***** Sorting by Name Done \n";
                    break;
            case 3 : sort(product.begin(), product.end(), cmpcompany);
                    cout << "***** Sorting by Company Name Done \n";
                    break;
            case 4 : return;
            default : cout << "Choose from options\n";
        }
    }while(option != 4);
};
void search(const vector<STOCKS> &product){
    
    string find;
    int option ;
    cin.ignore();
    do{
        vector<int> index;
        bool found=false;
        cout << "Enter \n1. ID \n2. Product Name\n3. Company\n4. Back\n";
        cin >> option;
        getline(cin, find);
    

        switch(option){
            case 1 : cout << "Enter ID : ";
                    getline(cin, find);
                    for(int i=0; i<product.size(); i++){
                        string id = to_string(product[i].id);
                        if( id.find(find) != string::npos){
                            index.push_back(i);
                            found=true;
                        }
                    }
                    break;
            case 2 : cout << "Enter Name : ";
                    getline(cin, find);
                    transform(find.begin(), find.end(), find.begin(), ::tolower);
                    for(int i=0; i<product.size(); i++){
                        string name=product[i].name;
                        transform(name.begin(), name.end(), name.begin(), ::tolower);
                        if( name.find(find) != string::npos){
                            index.push_back(i);
                            found = true;
                        }
                    }
                    break;
            case 3 : cout << "Enter Company : ";
                    getline(cin, find);
                    transform(find.begin(), find.end(), find.begin(), ::tolower);
                    for(int i=0; i<product.size(); i++){
                        string name=product[i].company;
                        transform(name.begin(), name.end(), name.begin(), ::tolower);
                        if( name.find(find) != string::npos){
                            index.push_back(i);
                            found = true;
                        }
                    }
                    break;
            case 4 : break;
            default : cout << "Choose from options\n";
        }

        if(!found){
            cout << "Product not found\n";
            continue;
        }
    
        for(int i=0; i<index.size(); i++){
            cout << i+1 << ". ";
            printproduct(product[index[i]]);
            if(product[index[i]].quantity <= 5) cout << "     *** ONLY " << product[index[i]].quantity << " REMAINING\n";
        }

    }while(option != 4);
    
    return;
};
