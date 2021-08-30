#include<bits/stdc++.h>

using namespace std;


bool check_bitmask(int bitmask, int substr_len){

	int on_bits;
	do{
		int t = bitmask & 1;
		on_bits += t;
	}while(bitmask >> 1);

	if(substr_len % 2 != 0 && on_bits == 1){
		return true;
	}
	else if( substr_len % 2 == 0 && on_bits == 0 ){
		return true;
	}	
	else{
		return false;
	}
}
int main()
{
	string s;
	cin>>s;
	int len = s.length();
	int ans = 0;	
	for(int i = 0 ; i < len ; i++){
	
		int substr_len;
		int bitmask = 0;
		for(int j = 0 ; j < i ; j++){
			int c = s[j] - 'a';
			substr_len = j - i + 1;
			bitmask = bitmask ^ (1 << c);
		}
		if(check_bitmask(bitmask, substr_len)){
			ans += 1;
		}
	}
	cout<<ans<<endl;
			
	return 0;
}
