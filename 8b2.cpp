#include<bits/stdc++.h>

using namespace std;

vector<int> adj[200005];
int seen = 0;
int visited[200005] = {0};

void dfs(int source){
	visited[source] = 1;
	seen++;
	for(int i = 0 ; i < adj[source].size() ; i++){
		if(!visited[adj[source][i]]){
			dfs(adj[source][i]);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> arr;
	vector<int> arr_sorted;
	int v;
	for(int i = 0 ; i < n ; i++){
		cin>>v;
		arr.push_back(v);
		arr_sorted.push_back(v);
	}
	sort(arr_sorted.begin() , arr_sorted.end());
	for(int i = 0 ; i < n ; i++){
		int wrong_idx = i;
		int elem = arr[i];
		//find in sorted array.
		vector<int>::iterator upper = upper_bound(arr_sorted.begin(), arr_sorted.end(), elem);
		int right_idx = upper - arr_sorted.begin() - 1;
		right_idx = n - right_idx -1;
		//cout<< wrong_idx << " " <<right_idx<<endl;
		adj[wrong_idx].push_back(right_idx);
	}
	/*
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < adj[i].size() ; j++){
			cout<< "i = " << i << " adjoint of =" << i << adj[i][j]<< " ";
		}
		cout<<endl;
	}
	*/
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		if(!visited[i]){
			seen = 0;
			dfs(i);
			ans += seen - 1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
