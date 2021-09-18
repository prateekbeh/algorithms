#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n,m;
	cin>>n>>m;
	set<int> alive;
	for(int i = 1 ; i <= n ; i++){
		alive.insert(i);
    }    
	int answer[n+1];
	memset(answer,0,sizeof(answer));
    for (int i = 0; i < m; i++) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        //l--, r--, x--;    
        set<int>::iterator it = alive.lower_bound(l);
        vector<int> toErase;        
        while(it != alive.end()){
            int cur = *it;            
            if(cur > r)
                break;                
            if(cur != x){    
                toErase.push_back(cur); 
				answer[cur] = x;
            }
            it++;
        }

        for (int j = 0; j < toErase.size(); j++)
            alive.erase(toErase[j]);
    }
	for(int i = 1 ; i <= n ; i++){
		cout<<answer[i]<< " ";
	}
}
