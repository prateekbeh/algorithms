#include<bits/stdc++.h>

using namespace std;

int main()
{

	vector<int> t ;
	t.push_back(3);
	t.push_back(2);
	t.push_back(1);

	vector<int>::iterator upper = upper_bound( t.begin() , t.end() , 3);
	cout<< upper - t.begin();
}
