#include<bits/stdc++.h>

using namespace std;


int getSum(int BITree[], int index)
{
    int sum = 0;
    index = index + 1;
    while (index>0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}

void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;
 
    while (index <= n)
    {
		BITree[index] += val;
		index += index & (-index);
	}
}

int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;
 
    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);
    return BITree;
}

int main()
{

	int n;
	cin>>n;
	int arr[n+1];
	for(int i = 0 ; i < n ; i++){
		cin>>arr[i];
	}
	//construct empty binary indexed tree
	
	int freq[100005] = {0};
	int *BITree = constructBITree(freq, 100005);
	int ans = 0;	
	for(int i = 0 ; i < n ; i++){
		int key = arr[i];
		int smaller_count = getSum(BITree,key-1);
		int bigger_count = getSum(BITree,key+1);
		ans += 1 + 2 * min(smaller_count ,bigger_count);
		updateBIT(BITree , 100005 , key ,1);
	} 	
	cout<<ans<<endl;
	return 0;
}
