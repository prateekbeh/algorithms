#include<bits/stdc++.h>

using namespace std;

bool compare(const pair<int,int> a, const pair<int,int> b){
	return a.second < b.second;
}

int main()
{
	int n;
	cin>>n;
	int arrival[50005];
	for(int i = 0 ; i < n ; i++)
		cin>>arrival[i];
	cin>>n;
	int duration[50005];
	pair<int,int> finish[50005];
	for(int i = 0 ; i < n ; i++){
		cin>>duration[i];
		finish[i] = make_pair(arrival[i] , arrival[i] + duration[i]);
	}
	
	sort(finish, finish+n , compare);
		
	int largest_finish = 0;
		
	int res = 0;
	for(int i = 0 ; i < n ; i++){
		if(finish[i].first >= largest_finish){
			largest_finish = finish[i].second;
			res++;
		}
	}
	cout<<res<<endl;
	return 0;
}

