#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	int x;
	cin>>x;
	int y;
	cin>>y;
	if ( x == 0 && y == 0 ){
		cout<<1<<endl;
		return 0;
	}
	else if(x == 0 || y == 0 ){
		cout<<2<<endl;
		return 0;
	}

	int h[x+2];
	h[0] = 0;
	h[x+1] = n;
	for(int i = 1 ; i <= x ; i++){
		cin>>h[i];
	}

	int v[y+2];
	v[0] = 0;
	v[y + 1] = m;
	for(int i = 1 ; i <= y ; i++){
		cin>>v[i];
	}
	
	sort(h , h + x + 2);
	sort(v , v + y + 2);
			
	int nax1 = 0;
	int tmp = 1;
	for(int i = 1 ; i <= x+1 ; i++){
		if(h[i] == h[i-1] + 1){
			tmp = tmp + 1;
		}
		else{
			tmp = 1;
		}
		nax1 = max(nax1, tmp);
	}
	tmp = 1;
	int nax2 = 0;
	for(int i = 1 ; i <= y+1 ; i++){
		if(v[i] == v[i-1] + 1){
			tmp = tmp + 1;
		}
		else{
			tmp = 1;
		}
		nax2 = max(nax2, tmp);
	}
	cout<<(nax1 + 1)*(nax2 + 1)<<endl;
	return 0;
} 
