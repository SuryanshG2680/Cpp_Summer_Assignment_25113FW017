//Program to Create student record system using arrays and strings
  
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;


int total(const vector<vector<int>> &marks, int student){
    int sum=0;
    for(int i=0; i<5; i++)
    sum += marks[student][i];
    return sum;
}
float percentage(const vector<vector<int>> &marks, int student){
    return (float)total(marks, student)/5;
}
char grade(const vector<vector<int>> &marks, int student){
    float percent = percentage(marks, student);
    if(percent > 90) return 'A';
    else if(percent > 75) return 'B';
    else if(percent > 60) return 'C';
    else if(percent > 45) return 'D';
    else if(percent > 35) return 'E';
    else return 'F';
}

void print(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks, int i );
void add(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks);
void display(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks);
void search(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks);
void update(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks);
void deletestudent(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks);
void sorting(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks);

int main(){

    vector<string> name;
    vector<int> roll;
    vector<int> eng;
    vector<vector<int>> marks;
    
    char yesno;
    do{
        cout << "Add Student Record? (y/n) : ";
        cin >> yesno;
        if(tolower(yesno) == 'y') {
            add(name, roll, marks);            
        }
    }while(tolower(yesno)!= 'n');

    int option;
    do{

        cout << "MENU =>\n"
        << "1. Add Student\n"
        << "2. Display students\n"
        << "3. Search Students\n"
        << "4. Update Student\n"
        << "5. Delete Student\n"
        << "6. Sort List\n"
        << "7. Exit\n";
        cin >> option;

        switch(option){
            case 1 : add(name, roll, marks);
            break;
            case 2 : display(name, roll, marks);
            break;
            case 3 : search(name, roll, marks);
            break;
            case 4 : update(name, roll, marks);
            break;
            case 5 : deletestudent(name, roll, marks);
            break;
            case 6 : sorting(name, roll, marks);
            break;
            case 7 : cout << "*** THANKYOU ***\n";
            return 0;
            default : cout << "Choose from options\n";
        }
    }while(option != 7);

    return 0;
}

void print(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks, int i ){
    
        cout << " Name         : " << name[i] << endl
        << "     Roll No.    : " << roll[i] << endl
        << "     Total Marks : " << total(marks, i) << endl
        << "     Percentage  : " << percentage(marks, i) << " %" << endl
        << "     Grade       : " << grade(marks, i ) << endl;
}
void add(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks){

    cout << "Enter Details :=> \n";

    cout << "Name : ";
    string newname;
    cin.ignore();
    getline(cin, newname);
    name.push_back(newname);
    
    cout << "Roll Number : ";
    int newroll;
    cin >> newroll;
    roll.push_back(newroll);
    
    vector<int> newMarks(5);
    cout << "Maths Marks : ";
    cin >> newMarks[0];

    cout << "English Marks : ";
    cin >> newMarks[1];

    cout << "Physics Marks : ";
    cin >> newMarks[2];

    cout << "Chemistry Marks : ";
    cin >> newMarks[3];

    cout << "PPS Marks : ";
    cin >> newMarks[4];

    marks.push_back(newMarks);
}
void display(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks){
    cout << endl;
    for(int i=0; i<name.size(); i++){
        cout << i+1 << ". ";
        print(name, roll, marks, i);
    }
}
void search(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks){
    int r;
    cout << "Enter Roll Number : ";
    cin >> r;

    for(int i=0; i<roll.size(); i++){
        if(roll[i] == r){
            cout << "\nStudent Found\n";
            print(name, roll, marks, i);
            return;
        }
    }
    cout << "Student Not Found\n";
    return;
}
void update(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks){
    int r;
    cout << "Enter Roll Number : ";
    cin >> r;

    for(int i=0; i<roll.size(); i++){

        if(roll[i] == r){

            cout << "Enter New Name : ";
            cin.ignore();
            getline(cin, name[i]);

            cout << "Enter New Roll Number : ";
            cin >> roll[i];

            cout << "Maths Marks : ";
            cin >> marks[i][0];

            cout << "English Marks : ";
            cin >> marks[i][1];

            cout << "Physics Marks : ";
            cin >> marks[i][2];

            cout << "Chemistry Marks : ";
            cin >> marks[i][3];

            cout << "PPS Marks : ";
            cin >> marks[i][4];

            cout << "Record Updated\n";
            return;
        }
    }
    cout << "Student Not Found\n";
    
    return;
}
void deletestudent(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks){
    int r;
    cout << "Enter Roll Number : ";
    cin >> r;

    for(int i=0; i<roll.size(); i++){

        if(roll[i] == r){

            name.erase(name.begin() + i);
            roll.erase(roll.begin() + i);
            marks.erase(marks.begin() + i);

            cout << "Record Deleted\n";
            return;
        }
    }
    cout << "Student Not Found\n";
    
    return;
}
void sorting(vector<string> &name, vector<int> &roll, vector<vector<int>> &marks){
    int option;
    do{
        cout << "Sort by =>\n"
        << "1. Name\n"
        << "2. Roll number\n"
        << "3. Percentage\n"
        << "4. Done\n";
        cin >>option;

        int n = name.size();
        switch(option){ 
            case 1 : for (int i = 0; i < n - 1; i++){
                        for (int j = i + 1; j < n; j++){
                            if (name[i] > name[j]){

                                swap(name[i], name[j]);
                                swap(roll[i], roll[j]);
                                swap(marks[i], marks[j]);
                            }
                        }
                    }
                    cout << "Sorting by name Done\n";
            break;

            case 2 : for (int i = 0; i < n - 1; i++){
                        for (int j = i + 1; j < n; j++){
                            if (roll[i] > roll[j]){

                                swap(name[i], name[j]);
                                swap(roll[i], roll[j]);
                                swap(marks[i], marks[j]);
                            }
                        }
                    }
                    cout << "Sorting by roll number Done\n";
            break;

            case 3 : for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (total(marks, i) < total(marks, j)) {

                                swap(name[i], name[j]);
                                swap(roll[i], roll[j]);
                                swap(marks[i], marks[j]);
                            }
                        }
                    }
                    cout << "Sorting by percentage Done\n";
            break;

            case 4 : return;
            default : cout << "Choose from options\n";

        }
        
        return;
    }while(option != 4);
}
