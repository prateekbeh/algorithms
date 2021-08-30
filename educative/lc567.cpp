#include<bits/stdc++.h>

using namespace std;

int hmap1[26];
int hmap2[26];
/*
pair<bool,bool> check_hmaps(){
	bool flag = true;
	bool ans = true;
	for(int i = 0 ; i < 26 ; i++){
		if(hmap2[i] != hmap1[i]){
			ans = false;
			if(hmap2[i] > hmap1[i]){
				flag = false;
			}
		}
	}
	pair<bool,bool> ret = make_pair(ans,flag);
	return ret;
}

int main()
{
	string s1,s2;
	cin>>s1>>s2;
	int len1 = s1.length(), len2 = s2.length();
	int ws = 0;
	for(int i = 0 ; i < len1; i++){
		hmap1[s1[i] - 'a']++;
	}
	pair<bool,bool> ret;
	for(int we = 0 ; we < len2 ; we++){
		hmap2[s2[we] - 'a']++;
		ret = check_hmaps();
		if(!ret.second){
			hmap2[s2[ws] - 'a']--;
			ws++;
		}
		if(ret.first){
			break;
		}
	}
	if(ret.first){
		cout<<"true"<<endl;
	}
	else{
		cout<<"false"<<endl;
	}
	return 0;
}
*/

int main(){

	// educative solution
	
	string s1,s2;
    cin>>s1>>s2;
    int len1 = s1.length(), len2 = s2.length();
    int ws = 0;
	
					

