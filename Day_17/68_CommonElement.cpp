//Program to find common elements

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

    int arr1[n1];
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

    int arr2[n2];
    cout << "Enter Array2 elements: ";
    for (int i=0; i<n2; i++){
        cin >> arr2[i];
    }

    int k=0, common[n1+n2], c=0;
    bool same=false;

    for(int i=0; i<n1; i++){
        same=false;
        for(int j=0; j<n2; j++){
            if(arr1[i] == arr2[j]){
                for(int l=0; l<k; l++) if(arr1[i] == common[l]) {
                    same= true; 
                    break;
                }
                if (same) break;
                common[k]= arr1[i];
                k++;
                break;
            }
        }
    }

    cout << "Common: ";
    for (int i=0; i<k; i++){
        cout << common[i] << " ";
    }

    return 0;
}