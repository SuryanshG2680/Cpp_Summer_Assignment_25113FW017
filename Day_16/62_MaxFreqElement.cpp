//Program to find element with maximum frequency

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
    cout << "Enter Array elements: ";
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    //FREQUENCY
    int p=0, num[n], freq, maxfreq=0;

    for(int i=0; i<n; i++)
    {
        freq=0;

        for(int j=0; j<n; j++)
        {
            if( arr[j] == arr[i])
            {
                freq++;
            }
        }

        bool already= false;
        for(int k=0; k<p; k++)
        {
            if(num[k] == arr[i]) 
            {
                already = true;
                break;
            }
        }

        if(freq > maxfreq)
        {
            maxfreq = freq;
            p=0;
            num[p]=arr[i];
        }

        if(freq == maxfreq && !already)
        {
            num[p++] = arr[i];
        }
    } 
    
    cout << "The element with maximum frequency is = ";
    for(int i=0; i<p; i++)
    {
        cout << num[i] << " ";
    }
    cout << endl << "Frequency = " << maxfreq;

    return 0;
}