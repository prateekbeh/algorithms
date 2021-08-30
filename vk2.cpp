#include<bits/stdc++.h>

using namespace std;

int main()
{

	int t;
	cin>>t;
	while(t--)
	{
		int h,w;
		cin>>h>>w;
		int arr[h+1][w+1];
		memset(arr,0,sizeof(arr));

		for(int i = 1 ; i <= w ; i+=2){
			arr[1][i] = 1;
		}
		for(int i = 2; i <= h ; i++){
			for(int j = 1 ; j <= w ; j++){
				if( i == 1 || i == h || j == 1 || j == w ){
					if(arr[i-1][j-1] == 1 || arr[i-1][j] == 1 || arr[i-1][j+1] == 1 || arr[i][j-1] == 1){
						arr[i][j] = 0;
					}
					else{
						arr[i][j] = 1;
					}
				}
			}
		}
		for(int i = 1 ; i<= h ; i++){
			for(int j = 1 ; j <= w ; j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
	}
	return 0;
}
				
