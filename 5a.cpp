#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
int main()
{
    int n;
    cin>>n;
    string s;

    char arr[1005][3005];
    int len = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>s;
        strcpy(arr[i],s.c_str());
    }
    string target;
    cin>>target;

    int len1 = strlen(arr[0]);

    int freq[3005][26];
    memset(freq,0,sizeof(freq));
    for(int i = 0 ; i < len1 ; i++){
        for(int j = 0 ; j < n ; j++){
            freq[i][arr[j][i] - 'a']++;
        }
    }

    ll dp[3005][3005];
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i <= len1 ; i++)	
    	dp[i][0] = 1;
    int len2 = target.length();
    for(int row = 1 ; row <= len1 ; row++){
    	for(int col = 1 ; col <= len2 ; col++){
    		if(freq[row-1][target[col-1] - 'a'] != 0){
    			dp[row][col] = ((dp[row-1][col-1] * freq[row-1][target[col-1] - 'a'])%MOD + dp[row-1][col]%MOD)%MOD;
     		}
     		else{
     			dp[row][col] = (dp[row-1][col] *  freq[row-1][target[col-1] - 'a']) % MOD;
     		}
    	}
    }
    cout<<dp[len1][len2]<<endl;
}
