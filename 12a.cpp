#include<bits/stdc++.h>

using namespace std;

#define INF 123456789
int main(){

	int n;
	cin>>n;
	int arr[100005] = {0};
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	int s = 0;
	for(int i = 1 ; i < n ; i++){
        if( arr[i] < arr[i - 1]){
			s = i - 1;
			break;
		}
    }
	int e = 0;
	for(int i = n - 1 ; i > 0 ; i--){
		if( arr[i] < arr[i-1]){
			e = i;
			break;
		}
	}
	//cout<<s<<e<<endl;
	//check whether the array is sorted or not.
	int max = -INF, min = INF;
	for(int i = s ; i <= e ; i++){
		if(arr[i] > max){
			max = arr[i];
		}
		if(arr[i] < min){
			min = arr[i];
		}
    }	
	//cout<<min<<" " <<max<<endl;
	for(int i = 0 ; i < s ; i++){
		if(arr[i] > min){
			s = i;
			break;
		}
	}
	for(int i = n - 1 ; i > e ; i--){
		if(arr[i] < max){
			e = i;
			break;
		}
	}
	cout<<e - s + 1<<endl;
	return 0;
}
