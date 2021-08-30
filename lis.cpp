/* Dynamic Programming C++ implementation
   of LIS problem */
#include <bits/stdc++.h>
using namespace std;
 

void print(int en ,int arr[] , int arr1[]){
	if(arr1[en] == -1){
		cout<<arr[en]<<" ";
		return;
	}
	else
		print(arr1[en], arr, arr1);
	cout<<arr[en]<<" ";
}

/* lis() returns the length of the longest
  increasing subsequence in arr[] of size n */
int lis(int arr[], int n)
{
    int lis[n];
 	int idx[n];
    lis[0] = 1;
	idx[0] = -1;
    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
		idx[i] = -1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1){
				idx[i] = j;
                lis[i] = lis[j] + 1;
			}
    }
	cout<<"Idx Start"<<endl;
	for(int i = 0 ; i < n ; i++){
		cout<<idx[i]<<" ";
	}
	cout<<"Idx end"<<endl;
	int nax = 0;
	for(int i = 0 ; i < n ; i++)
		if(lis[i] > nax)
			nax = i;
	cout<<"nax = "<<nax<<endl;
	print(7, arr, idx); 
    // Return maximum value in lis[]
    nax = *max_element(lis, lis + n);
	return nax;	

}
 
/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", lis(arr, n));
 
    return 0;
}
