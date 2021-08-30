#include<bits/stdc++.h>
using namespace std;

int main()
{
	int x,n;
	cin>>x>>n;

	int min_array[n-x+1];
	int arr[n+1];
	int st_index = 0;
	int val = 0;
	int min_loc1 = 0;
	int min_loc2 = 0;
	int min1 = min2 = INT_MAX;
	for(int i = 1 ; i <= n ; i++){

		cin>>arr[i];

		if(i >= x){
			st_pos = i - x + 1;
			if(arr[i] < min1){
				min2 = min1;
				min1 = arr[i];
				min_loc1 = i;
			}
			else if (arr[i] <= min2){
				min2 = arr[i];
				min_loc2 = i;
			}
			
				
				
			
			
			if(arr[st_pos]
			min_array[st_index] = min(val,arr[i]);
			st_index++;
		}
		val = min(val,arr[i]);
	}




	int ans = 0;
	for(int i = 0 ; i < st_index ; i++)
		ans = max(ans,val);
	cout<<ans<<endl;
}
