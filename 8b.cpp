#include<bits/stdc++.h>

using namespace std;

int visited[100005] = {0};
int seen;
int arr[100005] = {0};
int n;
void dfs(int source , int seen){
	
	visited[source] = 1;
	seen++;
	int child = n - arr[source] - 1;
	if(!visited[child]){
		dfs(child,seen);
	}
}

int solve(){
    int ans = 0;
    for(int i = 0; i < n ; i++){
       	if(!visited[arr[i]]){
            seen = 0;
            dfs(arr[i], seen);
            ans += seen - 1;
		}
	}
    return ans;       
}
int main()
{
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	cout<<solve();	

	return 0;
}
