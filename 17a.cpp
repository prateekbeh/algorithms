#include<bits/stdc++.h>

using namespace std;

#define pb push_back

vector<int> adjlist[200005];
int visited[200005];
int edge_count = 0;
int node_count = 0;

void dfs(int node){
	if(visited[node]){
		edge_count++;
		return;
	}
	else{
		visited[node] = 1;
		node_count++;
		for(int i = 0 ; i < adjlist[node].size() ; i++){
			edge_count++;
			dfs(adjlist[node][i]);
		}
	}
}

int main()
{
	int n,e;
	cin>>n>>e;
	int u,v;
	memset(visited,0,sizeof(visited));

	for(int i = 0 ; i < e ; i++){
		cin>>u>>v;
		adjlist[u].pb(v);
		adjlist[v].pb(u);
	}
	int cc = 0;
	int extra_edges = 0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < adjlist[i].size() ; j++){
			if(!visited[adjlist[i][j]]){
				dfs(adjlist[i][j]);
				extra_edges += (edge_count - node_count - 1);
				cc++;
			}
			edge_count = 0;
			node_count = 0;
		}
	}
	cout<<extra_edges<<endl;
	cout<< cc <<endl;
	if( extra_edges >= cc - 1){
		cout<< cc - 1 <<endl;
	}
	else{
		cout<<-1<<endl;
	}
}
