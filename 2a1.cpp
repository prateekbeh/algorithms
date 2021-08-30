#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int arr[1000001] = {0};
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	int x;
	cin>>x;

	int ws = 0;
	int mi = INF, mx = -INF;
	for(int we = 0 ; we < n ; we++){
		if( we - ws + 1 >= x ){
			mx = max(mx,arr[we]);
			ws++;
		}
		else{
			mx = max(mx , arr[we]);
		}
		mi = min(mi, arr[we]);
	}
	
