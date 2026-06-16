//Program to binary search

#include <iostream>
#include <vector>
using namespace std;


int main(){

    int n;
    cout << "Enter size of array = ";
    cin >> n;

    if(n<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }

    vector <int> arr(n);
    cout << "Enter Array elements in ascending order: ";
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    //SEARCH
    int search, c=0;
    cout << "Enter element to search = ";
    cin >> search;

    int BEG=0, END= n-1, INDEX=-1;
    while( BEG <= END){

        int MID= (END+BEG)/2;

        if( search > arr[MID] )
            BEG = MID+1;

        else if( search < arr[MID] )
            END = MID-1;    

        else {
            INDEX = MID;
            break;
        }
    }

    INDEX==-1? cout << "Element not found"
           : cout << "Element found at position " << INDEX;

    return 0;
}