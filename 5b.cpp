#include<bits/stdc++.h>
using namespace std;

int visited[105][105];
int grid1[105][105];
int grid2[105][105];
int n;
bool reg = true;

void dfs(int i,int j){
	if(visited[i][j]) return;
	if(grid1[i][j] != grid2[i][j]){
		reg = false;
	}
	if(grid1[i][j] == 1){
		visited[i][j] = 1;
		if(i + 1 < n)
			dfs(i+1,j);
		if(j + 1 < n)
			dfs(i,j+1);
		if(i - 1 >= 0 )
			dfs(i-1,j);
		if(j - 1 >= 0)
			dfs(i,j-1);
	}		
}
	
int main()
{

	cin>>n;
	char c;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>c;
			grid1[i][j] = c - 48;
		}
	}

	cin>>n;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin>>c;
			grid2[i][j] = c - 48;
		}
	}
	int res = 0;
	memset(visited,0,sizeof(visited));
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if(!visited[i][j] && grid1[i][j] == 1){
				reg = true;
				dfs(i,j);
				if(reg == true) res += 1;
			}
		}
	}
	cout<<res<<endl;
}
