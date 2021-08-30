#include<bits/stdc++.h>

using namespace std;


#define INF 123456789

string s;
int len;
char arr[6] = { '\0' , 'a' , 'e' , 'i' , 'o' , 'u' };

int dp[500006][7];

int solve( int next_elem , int end_with){

	//base case
	if(next_elem == len ){
		// check if the end_with is 'u' . If not 'u' the invalid string.
		if( arr[end_with] == 'u'){
			return 0;
		}
		else{
			//if the final ans is -ve then we say that string is invalid.
			return -INF;
		}
	}
	if(dp[next_elem][end_with] != -1) return dp[next_elem][end_with];

	int looking_for = end_with + 1;
	
	//printf("\n next_elem = %c , end_with = %d , looing_for = %c ",s[next_elem] , end_with , arr[looking_for] );
	
	if( s[next_elem] == arr[end_with]){
		return dp[next_elem][end_with] = solve( next_elem + 1, end_with ) + 1;
	}
	else if ( s[next_elem] == arr[looking_for]) {
		// two cases arise//
		int take_it = solve ( next_elem + 1, end_with + 1) + 1; // take it
		int not_take_it = solve ( next_elem + 1, end_with ); // do not take it
		dp[next_elem][end_with] = max( take_it , not_take_it);
		return dp[next_elem][end_with];

	}
	else{
		// move on if the next_element is either what we are looking for or the characeter ending with.
		return dp[next_elem][end_with] = solve( next_elem + 1, end_with );
	}
} 	

int main(){
	
	cin>>s;
	len = s.length();
	
	for(int i = 0 ; i < 500006 ; i++ ){
		for(int j = 0 ; j < 7 ; j++){
			dp[i][j] = -1;
		}
	}

	int ans = solve( 0 , 0); 
	if( ans < 0) cout<< 0 <<endl;
	else cout<<ans<<endl;
	return 0;
}
