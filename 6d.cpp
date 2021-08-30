#include<bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> adj[105];

int visited[105];
char node_val[105];

int dp[105][26];

void dfs(int u, int par){
	if(visited[u]){
		return;
	}
	visited[u] = 1;
	dp[u][node_val[u]  - 'a'] += 1;
	for(int i = 0 ; i < adj[u].size() ; i++){
		if(!visited[adj[u][i]]){
			dfs(adj[u][i],u);
			for(int j = 0 ; j < 26 ; j++){
				dp[u][j] += dp[adj[u][i]][j];
			}
		}
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		memset(node_val,0,sizeof(node_val));
		memset(visited,0,sizeof(visited));
		int n;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>node_val[i];
		}
		int u,v;
		for(int i = 0 ; i < n - 1 ; i++){
			cin>>u>>v;
			adj[u-1].pb(v-1);
			adj[v-1].pb(u-1);
		}
			
		dfs(0,-1);
		
		for(int i = 0 ; i < n ; i++){
			cout<<dp[i][node_val[i]-'a']<<" ";
		}
		for (auto& v : adj) {
 		  v.clear();
		}
	}
	return 0;
}
