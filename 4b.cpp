#include<bits/stdc++.h>

using namespace std;

class DSU{
	public:
		int parent[200005];
		int size[200005];

		void make_set(int v){
			parent[v] = v;
			size[v] = 1;
		}
		int find_set(int v){
			if(parent[v] == v){
				return v;
			}
			return parent[v] = find_set(parent[v]);
		}
		void union_set(int a , int b){
			a = find_set(a);
			b = find_set(b);
			if( size[a] < size[b]){
				swap(a,b);
			}
			parent[b] = a;
			size[a] += size[b];
		}
};

int main()
{
	DSU dsu;
	int n,g,q;
	cin>>n>>g;
	int origin[200005] = {0};
	int dest[200005] = {0};
	for(int i = 1 ; i <= n ; i++){
		dsu.make_set(i);
	}
	for(int i = g + 1 ; i <= n ; i++){
		for(int mult = 2 * i ; mult <= n ; mult += i){
			dsu.union_set(i,mult);
		}
	}
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		cin>>origin[i];
	}
	cin>>q;
	for(int i = 0 ; i < q ; i++){
		cin>>dest[i];
	}
	for(int i = 0 ; i < q ; i++){
		if( dsu.find_set(origin[i]) == dsu.find_set(dest[i]) ){
			cout<< 1 <<endl;
		}else{
			cout<< 0 << endl;
		}
	}
	return 0;
}
