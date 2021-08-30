#include<bits/stdc++.h>

using namespace std;

int main()
{
	int dp[2][100005];
	int inp[2][100005];
	memset(dp,0,sizeof(dp));
	memset(inp,0,sizeof(inp));
	
	int h;
	cin>>h;
	string s;
	int len;	
	dp[0][0] = 1;
	for(int i = 0 ; i < h ; i++){
		cin>>s;
		len = s.length();
		for(int j = 0 ; j < len ; j++){
			if(i == 0){
				inp[i][j] = s[j] - 'a';
				if( j != 0){
					if(inp[i][j] == inp[i][j-1]){
						dp[i][j] = dp[i][j-1];
					}
					else{
						dp[i][j] = dp[i][j-1] + 1;
					}
				}
			}
			
			else{
				inp[1][j] = s[j] - 'a';
				if( j == 0)
				{
					if(inp[1][j] == inp[0][j])
					{
						dp[1][j] = dp[0][j];
					}
					else
					{
						dp[1][j] = dp[0][j] + 1;
					}
				}
				else
				{
					//rest of the cases.
					if(inp[1][j] == inp[0][j] && inp[1][j] == inp[1][j-1])
					{
						//cheeck for the same group.
						if(dp[1][j-1] == dp[0][j-1] || dp[0][j] == dp[0][j-1]){
							 dp[1][j] = dp[1][j-1] + dp[0][j] - dp[0][j-1];
						}else{
							// they belong to different group.
							dp[1][j] = dp[1][j-1] + dp[0][j] - dp[0][j-1] - 1;
						}
					}
					else if(inp[1][j] == inp[0][j] || inp[1][j] == inp[1][j-1]){
						dp[1][j] = dp[1][j-1] + dp[0][j] - dp[0][j-1];
					}
					else{
						dp[1][j] = dp[1][j-1] + dp[0][j] - dp[0][j-1] + 1;
					}
				}
			}
		}
		for(int k = 0 ; k < len ; k++){
			if(i != 0){
            	inp[0][k] = inp[1][k];
            	dp[0][k] = dp[1][k];
       		}
		}
	}
	cout<<dp[0][len-1]<<endl;
	return 0;
}

/*
	old code
	
    if(h == 0)
		cout<<dp[0][len-1]<<endl;
	else
		cout<<dp[1][len-1]<<endl;	
	*/

