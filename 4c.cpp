#include<bits/stdc++.h>

using namespace std;

#define pb push_back

typedef map<int, vector<int> > GraphAdjT;
long long int INF = LLONG_MAX;

typedef long long ll;

ll subtree_sum[100005];
int visited[100005];

vector<int> val;
void dfs(int src , int par, GraphAdjT &adj){
		visited[src] = 1;
		subtree_sum[src] += val[src];
		for(int i = 0 ; i < adj[src].size(); i++){
			if( !visited[adj[src][i]]){
				dfs(adj[src][i], src, adj);
				subtree_sum[src] += subtree_sum[adj[src][i]];
			}
		}
		
}


int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;	
		cin>>n;
		
		vector<pair<int,int> > edgelist;
		//vector<vector<int> > adj(100005);
		GraphAdjT adj;
		int u,v;
		
		for(int i = 0 ; i < n ; i++){
			visited[i] = 0;
		}
	
		for(int i = 0 ; i < n - 1; i++){
			cin>>u>>v;
			u--;v--;
			edgelist.push_back(make_pair(u,v));
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int va;
		for(int i = 0 ; i < n ; i++){
			cin>>va;
			val.push_back(va);
		}
		dfs(0,-1, adj);
		ll lower_sum = 0;
		ll remaining_sum = 0;
		ll diff = 0;
		int res = -1;
		ll ans = INF;
		
		for(int i = 0 ; i < n - 1; i++){
			u = edgelist[i].first;
			v = edgelist[i].second;
            lower_sum = min(subtree_sum[u] , subtree_sum[v]);
			remaining_sum = subtree_sum[0] - lower_sum;
			diff = abs(lower_sum - remaining_sum);
			if( diff < ans ){
				ans = diff;
				res = i;
			}
        }
		cout<<res+1<<endl;		
		
		//for(int i = 0 ; i < n ; i++){
		//	adj[i].clear();
		//}
		val.erase(val.begin() , val.end());
		memset(subtree_sum,0,sizeof(subtree_sum));		
		
	}
	return 0;
}
