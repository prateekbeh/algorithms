#include<bits/stdc++.h>

using namespace std;

void solve(int r,int g, int b){
	int min_flowers = min(r,min(g,b));
	
	int no_mix = r/3 + b/3 + g/3;
	int one_mix = 0;
	int two_mix = 0;
	if(min_flowers >= 1){
		one_mix = 1;
	}
	else{
		one_mix = 0;
	}
	one_mix += (r - 1)/3 + (b - 1)/3 + (g - 1)/3;

	if(min_flowers >= 2){
		two_mix = 2;
	}else{
		two_mix = 0;
	}
	two_mix += (r - 2)/3 + (b - 2)/3 + (g - 2)/3;
	cout<< max( no_mix , max( one_mix , two_mix));
	
}
int main(){

	int r,g,b;
	cin>>r>>g>>b;
	solve(r,g,b);
	return 0;
}
