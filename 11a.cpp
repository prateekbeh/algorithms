#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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
	/*
	for(auto it = arr.begin() ; it != arr.end() ; it++){
		cout<<*it<<" ";
	}
	*/
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
			

int main()
{
	int n;
	cin>>n;
	ll A[100];
	
	for(int i = 0 ; i < n ; i++){
		cin>>A[i];
	}
	sort(A,A+n,compare);
	for(int i = 0 ; i < n ; i++){
		cout<<A[i]<<" ";
	}
	return 0;
}
