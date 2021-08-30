/******************READ-ONLY PART BEGINS*****************/
#include <bits/stdc++.h>
using namespace std;
/*******************READ-ONLY PART ENDS******************/

/******************READ-ONLY PART BEGINS*****************/


const int SIZE =  1000000;
vector<int> lightBulbs(vector<int> states, vector<int> numbers){
	
	bool prime[SIZE + 1];
    memset(prime, true, sizeof(prime));
 
	int spf[SIZE];
    memset(spf, 0 , sizeof(spf));
    for (int i = 2; i * i <= SIZE; i++)
    {
        if (prime[i] == true)
        {
			spf[i] = i;
            for (int j = i * i; j <= SIZE; j += i){
				spf[j] = i;
                prime[j] = false;
			}
        }
    }
		
	int global_arr[SIZE];
    memset(global_arr, 0 , sizeof(global_arr));
	
	bool seen[SIZE];
    memset(seen, false , sizeof(seen));
	
	for(int i = 0 ; i < numbers.size() ; i++){
		int num = numbers[i];
		while(num != 1){
			if(!seen[spf[num]]){
				global_arr[spf[num]] ^= 1;
				seen[spf[num]] = true;
			}
			num /= spf[num];
		}
    	memset(seen, false , sizeof(seen));
	}
	/*	
	for(int i = 0 ; i < SIZE ; i++){
		if(spf[i] == i){
			if(global_arr[i]){
				for(int j = i ; j < SIZE ; j += i){
					states[i] ^= 1;
				}
			}
		}
	}
	*/
	return states;	
}		

	
int main() {
	int n; cin >> n;
	vector<int> states(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> states[i];
	}

	int m; cin >> m;
	vector<int> numbers(m);
	for(int i = 0 ; i < m ; i++) {
		cin >> numbers[i];
	}

	vector<int> res = lightBulbs(states, numbers);

	return 0;
}
