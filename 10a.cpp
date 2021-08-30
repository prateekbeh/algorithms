#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	int len = s.length();
 	
    int BMAP[128] = {0};
    int cmap[128] = {0};
    int DC = 0;
    int dc = 0;
    int minLength = len + 1 ;
    int start = len + 1;

	for(int i = 0 ; i < len ; i++){
        DC += (BMAP[s[i]] == 0);
		BMAP[s[i]] = 1;
	}	


    int ws = 0;
    for (int we = 0;  we < len ; ++we) {
	 int v = s[we];
     cmap[v] += 1;
     dc += cmap[v] == 1;
    
	
     while (dc >= DC) { // condition is true
       
       if (minLength > we -ws + 1) {
		  minLength =  we -ws + 1;
          start = ws;
       }
	   cmap[s[ws]] -= 1;
       dc -= (cmap[s[ws]] == 0);
		++ws;
      } 
    } 	
    printf("%d\n",minLength );
	return 0;
}
