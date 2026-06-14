//Program to union of arrays

#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n1, n2;
    cout << "Enter size of array 1 = ";
    cin >> n1 ;

    if(n1<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }

    vector <int> arr1(n1);
    cout << "Enter Array1 elements: ";
    for (int i=0; i<n1; i++){
        cin >> arr1[i];
    }

    cout << "Enter size of array 2 = ";
    cin >> n2 ;

    if(n2<=0)
    {
        cout << "Invalid Array size";
        return 0;
    }
    
    vector <int> arr2(n2);
    cout << "Enter Array2 elements: ";
    for (int i=0; i<n2; i++){
        cin >> arr2[i];
    }

    int k=0, uni[n1+n2]={0}, c=0;

    //First Array
    for(int i=0; i<n1; i++){
        c=0;
        for(int j=0; j<k; j++){
            if(arr1[1] == uni[j]){
                c++;
                break;
            }
        }
        if(c==0) uni[k++]=arr1[i];
    } 
    //Second array
    for(int i=0; i<n2; i++){
        c=0; 
        for(int j=0; j<k; j++){
            if(arr2[i] == uni[j]){ 
                c++;
                break;
            }
        }
        if(c==0) uni[k++]=arr2[i];
    }
    
    cout << "Union: ";
    for (int i=0; i<k; i++){
        cout << uni[i] << " ";
    }

    return 0;
}