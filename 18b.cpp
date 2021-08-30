#include<bits/stdc++.h>

using namespace std;

int paint[1005][1005];
int visited[1005][1005];

int n;
int len;

//wrong answer on test case 52/
void dfs(int i,int j){
	if(visited[i][j]){
		return;
	}
	if( i >= n || i < 0 || j >= len || j < 0)
		return;
	else{
		visited[i][j] = 1;
		if( paint[i][j] == paint[i+1][j]){
			dfs(i+1,j);
		}
		if( paint[i][j] == paint[i][j+1]){
			dfs(i,j+1);
		}
		if( paint[i][j] == paint[i-1][j]){
			dfs(i-1,j);
		}
		if( paint[i][j] == paint[i][j-1]){
			dfs(i,j-1);
		}
	}
}
			

int main()
{

	cin>>n;
	string s;
	len = 0;
	memset(paint,0,sizeof(paint));
	memset(visited,0,sizeof(visited));
	for(int i = 0 ; i < n ; i++){
		cin>>s;
		len = s.length();
		for(int j = 0 ; j < len ; j++){
			paint[i][j] = s[j] - 'a';
		}
	}
	int cc = 0;
	for(int i = 0; i < n ; i++){
		for(int j = 0 ; j < len ; j++){ 
			if(!visited[i][j]){
				dfs(i,j);
				cc++;
			}
		}
	}
	cout<<cc<<endl;
	return 0;
}
