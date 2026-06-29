//Program to Create mini library system

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

struct library{

    char block;
    int section;
};
struct bookinfo{

    string id;
    string name;
    int year;
    string author;
    string genre;

    struct library location;
    int number;
    bool available;

};

void search(const vector<bookinfo> &book);
void sorting(vector<bookinfo> &book);
void addbook(vector<bookinfo> &book);
void removebook(vector<bookinfo> &book);
void display(const vector<bookinfo> &book);
void updateinfo(vector<bookinfo> &book);

string lower(string str){
    for(char &c : str)  
    c = tolower(c);
    return str;
}
void printbookinfo(const bookinfo &x);

bool cmpname(bookinfo const &a, bookinfo const &b){
    return a.name < b.name;
}
bool cmpid(bookinfo const &a, bookinfo const &b){
    return a.id < b.id;
}
bool cmpauthor(bookinfo const &a, bookinfo const &b){
    return a.author < b.author;
}
bool cmpyear(bookinfo const &a, bookinfo const &b){
    return a.year < b.year;
}

int main(){

    cout << "Enter Library Description : \n";

    vector <bookinfo> books;
    int c=0;
    char add;

    do{
        bookinfo book;
        cout << "Enter book name : ";
        getline(cin, book.name);

            cout << "Enter 8-digit Book ID : ";
        while(true){
            getline(cin, book.id);

            if ( book.id.length() != 8 || !all_of( book.id.begin(), book.id.end(), ::isdigit)) {

            cout << "ERROR !! ID must contain exactly 8 digits\n";
            continue;
            }
            bool duplicate = false;

            for(const bookinfo &x: books){
                if(x.id == book.id){

                    cout << "ID already exists\n";
                    duplicate = true;
                    break;
                }
            }
            if(duplicate) continue;

            break;
        }


            cout << "Publish Year? ";
            cin >> book.year;

        while(book.year <1000 || book.year > 2026){
            cout << "ERROR !! Publish Year must be between 1000 and 2027\n";
            cout << "Publish Year? ";
            cin >> book.year;
        };

        cin.ignore();
        cout << "Author name: ";
        getline(cin, book.author);

        cout << "Genre : ";
        getline(cin, book.genre);

        cout << "Location ? Block & Section : ";
        cin >> book.location.block >> book.location.section;

            cout << "Number of book currently available : ";
            cin >> book.number;

        while(book.number < 0){
            cout << "Number must be greater than or equal to zero\n";
            cout << "Number of book currently available : ";
            cin >> book.number;
        };
        // do{cout << "Is the book currently available : (y/n) ";
        // cin >> available;
        // }while(available != 'n' && available != 'y' && available != 'Y' && available != 'N');

        if(book.number == 0) book.available = false;
        else book.available = true;

        books.push_back(book);
        c++;
        do{
            cout << "Add Book ? (y/n) ";
            cin >> add;
            cin.ignore();
        }while(add != 'n' && add != 'y' && add != 'Y' && add != 'N');

        if(add=='n' || add=='N') break;

    }while(add == 'y' || add == 'Y');


    int option;
    do{
        
        cout << "\n******** LIBRARY MANAGEMENT SYSTEM *********\n"
             << "\nMENU SYSTEM :=> \n" 
             << "1. Search\n"
             << "2. Sort\n"
             << "3. Add Book\n"
             << "4. Remove Book\n"
             << "5. Display\n"
             << "6. Update Book Information\n"
             << "7. Exit\n";

        cin >> option;

        switch(option){
            case 1 : search(books);
                    break;
            case 2 : sorting(books);
                    break;
            case 3 : addbook(books);
                    break;
            case 4 : removebook(books);
                    break;
            case 5 : display(books);
                    break;
            case 6 : updateinfo(books);
                    break;
            case 7 : cout << "\n~~~~~~ THANKYOU ~~~~~\n";
                    return 0;
            default : cout << "Choose from given option\n";
            }
        }while (option != 7);

    return 0;
}

void search(const vector<bookinfo> &book){

    int option, c=0;
    string name;
    bool found=false;

    while(true){
        cout << "\nSEARCH BY :=> \n" 
             << "1. Name\n"
             << "2. Book ID\n"
             << "3. Author\n"
             << "4. Genre\n"
             << "5. Back\n";

        cin >> option;
        cin.ignore();
        switch(option){

            case 1 : cout << "Enter book name : ";
                    getline(cin, name);

                    found = false;
                    c=1;
                    for(const bookinfo &x : book){

                        if(lower(name) == lower(x.name)){
                            cout << c << ". " ;
                            printbookinfo(x);
                            c++;
                            found = true;
                        }
                    }
                    if(!found) cout << "\nNo Records Found\n";
                    break;

            case 2 : cout << "Enter book ID : ";
                    getline(cin, name);

                    found = false;
                    c=1;
                    for(const bookinfo &x : book){
                        if(name == x.id){
                            cout << c << ". " ;
                            printbookinfo(x);
                            c++;
                            found = true;
                        }
                    }
                    if(!found) cout << "\nNo Records Found\n";
                    break;

            case 3 : cout << "Enter book Author : ";
                    getline(cin, name);

                    found = false;
                    c=1;
                    for(const bookinfo &x : book){
                        if(lower(name) == lower(x.author)){
                            cout << c << ". " ;
                            printbookinfo(x);
                            c++;
                            found = true;
                        }
                    }
                    if(!found) cout << "\nNo Records Found\n";
                    break;

            case 4 : cout << "Enter book genre : ";
                    getline(cin, name);

                    found = false;
                    c=1;
                    for(const bookinfo &x : book){
                        if(lower(name) == lower(x.genre)){
                            cout << c << ". " ;
                            printbookinfo(x);
                            c++;
                            found = true;
                        }
                    }
                    if(!found) cout << "\nNo Records Found\n";
                    break;

            case 5 : return;

            default : cout << "Choose from given option\n";
        }
    }
};
void sorting(vector<bookinfo> &book){

    cout << "Sort By :=> \n"
        << "1. Name\n"
        << "2. Book ID\n";
    int option;

    do{
        cin >> option;
        switch(option){
            case 1 : sort(book.begin(), book.end(), cmpname); 
                    cout << "***** Sorting by Name Done \n";
                    break;

            case 2 : sort(book.begin(), book.end(), cmpid); 
                    cout << "***** Sorting by ID Done \n";
                    break;
                     
                     default : cout << "Choose from Options \n";
        }
    }while(option < 1 || option > 2);
};
void addbook(vector<bookinfo> &book){

    bookinfo newbook;
        cin.ignore();
        cout << "Enter book name : ";
        getline(cin, newbook.name);

        cout << "Enter 8-digit Book ID : ";
        getline(cin, newbook.id);

        while( newbook.id.length() != 8 || !all_of( newbook.id.begin(), newbook.id.end(), ::isdigit)){
            cout << "ERROR !! Enter numbers only\n";
            cout << "Enter 8-digit Book ID : ";
            getline(cin, newbook.id);
        };

        cout << "Publish Year? ";
        cin >> newbook.year;

        while(newbook.year <1000 || newbook.year > 2026){
            cout << "ERROR !! Publish Year must be between 1000 and 2027\n";
            cout << "Publish Year? ";
            cin >> newbook.year;
        };

        cin.ignore();
        cout << "Author name: ";
        getline(cin, newbook.author);

        cout << "Genre : ";
        getline(cin, newbook.genre);

        cout << "Location ? Block & Section : ";
        cin >> newbook.location.block >> newbook.location.section;

        cout << "Number of book currently available : ";
        cin >> newbook.number;

        while(newbook.number < 0){
            cout << "Number must be greater than or equal to zero\n";
            cout << "Number of book currently available : ";
            cin >> newbook.number;
        };

        if(newbook.number == 0) newbook.available = false;
        else newbook.available = true;

        book.push_back(newbook);
};
void removebook(vector<bookinfo> &book){

    string removeid;
    bool found = false;
    char yesno;
    cout << "Enter Book ID to remove : ";
    cin >> removeid;

    for(int i=0; i<book.size(); i++){
        if(removeid == (book[i].id)){
            found= true; 
            printbookinfo(book[i]);
            cout << "Press 'Y' to confirm removing this book \n";
            cin >> yesno;

            if(yesno == 'y' || yesno == 'Y'){
                book.erase(book.begin() + i );
                cout << "Book Removed successfully\n";
            }
            break;
        }
    }
    if(!found) cout << "No Record Found\n";
    return;
};
void display(const vector<bookinfo> &book){

    int c=1;
    for(const bookinfo &x : book){

        cout << c << ". ";
        printbookinfo(x);
        c++;
    }
};
void updateinfo(vector<bookinfo> &book){

    int i=0, option;
    bool found=false;
    string updateid;
    char yesno;
    cout << "Enter Book ID to update information : ";
    cin >> updateid;

    for(i; i<book.size(); i++){
        if(updateid == book[i].id){
            printbookinfo(book[i]);
            found=true;
            break;
        }
    }
    if(!found) {
        cout << "Record Not Found\n";
        return;
    }
    do{
        cout << "What to Update ? \n"
            << "1. Name\n"
            << "2. Book ID\n"
            << "3. Author\n"
            << "4. Publish Year\n"
            << "5. Genre\n"
            << "6. Location\n"
            << "7. Number of books Available\n"
            << "8. Done\n";
        cin >> option;

        switch (option){

            case 1 : cout << "Enter New Name : ";
                    cin.ignore();
                    getline(cin, book[i].name);
                    cout << "Name Updated Successfully\n";
                    break;
            case 2 : cout << "Enter New Book ID : ";
                    cin.ignore();
                    getline(cin, book[i].id);
                    while( book[i].id.length() != 8 || !all_of( book[i].id.begin(), book[i].id.end(), ::isdigit)){
                        cout << "ERROR !! Enter numbers only\n";
                        cout << "Enter 8-digit Book ID : ";
                        getline(cin, book[i].id);
                    };
                    cout << "Book ID Updated Successfully\n";
                    break;
            case 3 : cout << "Enter New Author Name : ";
                    cin.ignore();    
                    getline(cin, book[i].author);
                    cout << "Author Name Updated Successfully\n";
                    break;
            case 4 : cout << "Enter New Publish Year : ";
                    cin >> book[i].year;
                    cout << "Publish Year Updated Successfully\n";
                    break;
            case 5 : cout << "Enter New Genre : ";
                    cin.ignore();
                    getline(cin, book[i].genre);
                    cout << "Genre Updated Successfully\n";
                    break;
            case 6 : cout << "Enter New Location : ";
                    cin >> book[i].location.block >> book[i].location.section;
                    cout << "Location Updated Successfully\n";
                    break;
            case 7 : cout << "Enter Number of books available : ";
                    cin >> book[i].number;
                    book[i].available = (book[i].number > 0);
                    cout << "Number of books available Updated Successfully\n";
                    break;
            case 8 : break;

            default : cout << "Choose from options \n";
        }
    }while(option != 8);

    cout << "New Information => \n";
    printbookinfo(book[i]);

    return;
};

void printbookinfo(const bookinfo &x){

    cout << "    Name        : " << x.name 
    << "\n\tBook ID      : " << x.id
    << "\n\tAuthor       : " << x.author 
    << "\n\tYear         : " << x.year 
    << "\n\tGenre        : " << x.genre 
    << "\n\tLocation     : " << x.location.block << "-" << x.location.section 
    << "\n\tCopies       : " << x.number
    << "\n\tStatus       : " << (x.available? "Available" : "Not Available") << endl;
}