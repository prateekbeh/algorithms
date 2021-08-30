#include<bits/stdc++.h>
#include<map>
using namespace std;



map<char,int> create_map()
{
  map<char,int> m;
  m['a'] = 1;
  m['e'] = 2;
  m['i'] = 3;
  m['o'] = 4;
  m['u'] = 5;
  return m;
}

int main(){
	string s;
	cin>>s;
	int len = s.length();
	
	int dp[5005][5] = {0};
		
	map<int,int> pos; 
	char arr[5] = { 'a', 'e', 'i','o','u' };
	map<char,int> m = create_map();

	//initialize position array	
	for(int i = 0 ; i < 5 ; i++){
		pos[arr[i] - 'a'] = 0;
	}

	vector<char> vow(arr,arr+5);
	vector< pair< char , int > > vow
	for(int i = 1 ; i <= len ; i++){
		for(int j = 1 ; j <= 5 ; j++){
			if( vow[j] <= s[i-1]){
				// letters ending with previous vowels.
				// i -> last character position of vowel j.
				// j -> current vowel.
				// another for loop to check for the pos[j]th row.
				for(int k = 0 ; k < 5 ; k++){
					// we need to fill the dp table for the last element and the jth vowel.
					//if( i == 3 ){
						cout<< vow[j] << " its last position " << pos[j] <<" result dp[ "<< i << "][" << j << "] till now = "<< dp[i][j] << endl ;
					//}
					dp[i][j] = max(dp[pos[j]][k] + 1 ,dp[i][j]);
				}
			}
		}
		pos[m[s[i-1]]] = i;
		cout<<"After setting "<<s[i-1] <<  " " << "its last position " <<pos[m[s[i-1]]]<<endl;
	}
	
	int ans = -1;
	
	for(int i = 1 ; i <= len ; i++){
		cout<<s[i-1]<<" ";
        for(int j = 0 ; j < 5 ; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 0 ; i < 5 ; i++){
		ans = max(ans, dp[len][i]);
	}
	cout<<ans<<endl;
	return 0;
}
