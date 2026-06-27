//Program to Create menu-driven array operations system
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

void display(const vector<int> &array){
    
    for(int i : array){
        cout << i << " ";
    }
    cout << endl;
};
void add(vector<int> &array){
    
    int num;
    cout << "Enter element : ";
    cin >> num;
    array.push_back(num);
};
void deleteelement(vector<int> &array) {
    int num;
    vector<int> positions;

    cout << "Enter element to remove: ";
    cin >> num;

    for (int i = 0; i < array.size(); i++) {
        if (array[i] == num) {
            positions.push_back(i);
        }
    }

    if (positions.empty()) {
        cout << "Element not found\n";
        return;
    }

    cout << "Element found at index(s): ";
    for (int i : positions) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Enter index to remove OR -1 to remove all: ";
    int option;
    cin >> option;

    
        if (option == -1) {
            for (int i = positions.size() -1 ; i >= 0; i--) {
                array.erase(array.begin() + positions[i]);
            }
        } 
        else if(option >= -1 && option < array.size()){
            for (int i = 0; i < positions.size(); i++) {
                if (positions[i] == option) {
                    array.erase(array.begin() + option);
                    break;
                }
                else{
                    cout << "Element not found at given index\n";
                    break;
                }
            }
        }
        else{
            cout << "Invalid option\n";
            return;
        }
}
void maximum(const vector<int> &array){
    
    int max=array[0];

    if(array.empty()) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Maximum element is : ";

    for( int i=0; i<array.size(); i++){
        if(array[i] > max)  max=array[i];
    }
    cout << max << endl;
};
void minimum(const vector<int> &array){

    int min=array[0];

    if(array.empty()) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Minimum element is : ";

    for( int i=0; i<array.size(); i++){
        if(array[i] < min)  min=array[i];
    }
    cout << min << endl;
};
bool desc(int a, int b) {
    return a > b;
}
void sorting(vector<int> &array){
    
    int option;
    cout << "Sort in :\n 1. Ascending\n 2. Decending\n";
    while(true){
        cin >> option;
        if(option != 1 && option != 2){
            cout << "choose from options";
            continue;
        }
        if(option == 1)
            sort(array.begin(), array.end());
        if(option == 2)
            sort( array.begin(), array.end(), desc);
        break;
    }
    cout << "Sorted array =>\n";
    display(array);
}
void maxfreq(const vector<int> &array){
    
    int p=0, freq, maxfreq=0;
    vector<int> num(array.size());
    for(int i=0; i<array.size(); i++) {
       
        freq=0;
        for(int j=0; j<array.size(); j++) {
            if( array[j] == array[i]) {
                freq++;
            }
        }

        bool already= false;
        for(int k=0; k<p; k++) {
            if(num[k] == array[i]) {
                already = true;
                break;
            }
        }

        if(freq > maxfreq) {
            maxfreq = freq;
            p=0;
            num[p]=array[i];
        }

        if(freq == maxfreq && !already) {
            num[p++] = array[i];
        }
    } 
    
    cout << "The element with maximum frequency is = ";
    for(int i=0; i<p; i++) {
        cout << num[i] << " ";
    }
    cout << endl << "Frequency = " << maxfreq << endl;
};
void arraysum(const vector<int> &array){
    int sum=0;
    
    if(array.empty()) {
        cout << "Array is empty\n";
        return;
    }
    for(int i=0; i<array.size(); i++){
        sum += array[i];
    }
    cout << "Sum = " << sum << endl;
};
void sumavg(const vector<int> &array){
    int sum=0;
    if(array.empty()){
        cout << "Array is empty\n";
        return;
    }
    for(int i=0; i<array.size(); i++){
        sum += array[i];
    }
    cout << "Sum Average = " << (float)sum/array.size() << endl;
    
};
void duplicates(const vector<int> &array){
    int count=0;
    cout << "Duplicates in the array are : ";

    for(int i=0; i<array.size(); i++) {

       int c=0;
       for (int j=i+1; j<array.size(); j++) {
           if(array[i] == array[j]) c++;
       }

       for (int k=0; k<i; k++) {
            if(array[i] == array[k]) c=0;
       }
       
       if(c>0) {
        cout << array[i] << " ";
        count++;
       } 
    if(i==array.size()-1) cout << endl;
    }
    if(count==0) cout << "\rNo duplicates found in given array\n";
    return;
};
void removeduplicates(vector<int> &array){
    for(int i=0; i<array.size(); i++)
    {
        for (int j=i+1; j<array.size(); j++)
        {
            if(array[i] == array[j] )
            {
                array.erase(array.begin() + j);
                j--;
            }
        }
    }

    cout << "Array after removing duplicates: \n";
    display(array);
};

int main(){

    vector<int> array;
    int option, size;
    
    cout << "\n*** ARRAY OPERATION SYSTEM ***\n\n";

    cout << "Enter number of elements : ";
    cin >> size;
    cout << "Enter Array elements : ";
    for(int i=0; i<size; i++){
        int x;
        cin >> x;
        array.push_back(x);
    }
    
    do{
        cout << "\nMENU =>\n"
            << "1. Display Array\n"
            << "2. Add element\n"
            << "3. Delete element\n"
            << "4. Find maximum\n"
            << "5. Find minimum\n"
            << "6. Sort Array \n"
            << "7. Find Maximum frequency element\n"
            << "8. Sum of Array\n"
            << "9. Average of sum of array\n"
            << "10. Find Duplicates\n"
            << "11. Remove Duplicates\n"
            << "12. Exit\n";

        cin >> option;
        switch(option){
            case 1 : display(array);
                    break;
            case 2 : add(array);
                    break;
            case 3 : deleteelement(array);
                    break;
            case 4 : maximum(array);
                    break;
            case 5 : minimum(array);
                    break;
            case 6 : sorting(array);
                    break;
            case 7 : maxfreq(array);
                    break;
            case 8 : arraysum(array);
                    break;
            case 9 : sumavg(array);
                    break;
            case 10 : duplicates(array);
                    break;
            case 11 : removeduplicates(array);
                    break;
            case 12 : cout << "*** THANK YOU ***\n";
                    return 0;
            default : cout << "Choose from given operations to perform\n";
        }
    }while (option != 12);

    return 0;
}
