#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>b[i];
	}
	
	int confict_right[n];
	int safe[n];
	for(int i = 0 ; i <= n ; i++){
		conflict_right[i] = n;
		safe[i] = n;
	}
	
	for(int i = 0; i < m ; i++){
		if(a[i] < b[i]){
			conflict_right[a[i]] = min(conflict_right[a[i]] , b[i]);
		}
		else{
			conflict_right[b[i]] = min(conflict_right[b[i]] , a[i]);
		}
	}
	for(int i = 0 ; i < n ; i++){
		safe[i] = min(safe[i+1] , conflict_right[i]);
	}
	return 0;
}
