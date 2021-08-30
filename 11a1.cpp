#include <bits/stdc++.h>
using namespace std;
 
/* Function to sort an array using insertion sort*/


bool compare(ll a , ll b){
    vector <int> arr;
    vector <int>  brr;
    while(a % 10 != 0){
        arr.push_back(a%10);
        a = a / 10;
    }
    arr.push_back(a);
    reverse(arr.begin() , arr.end());
    while(b % 10 != 0){
        brr.push_back(b%10);
        b = b / 10;
    }
    brr.push_back(b);
    reverse(brr.begin(), brr.end());
    int i = 0 , j = 0;
    while(i < arr.size() || j < brr.size()){
        if(arr[i] > brr[i]){
            return a < b;
        }
        else{
            return a > b;
        }
        i++;j++;
    }
    return arr.size() > brr.size();
}

void insertionSort(ll arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && compare(arr[j] > key))
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

