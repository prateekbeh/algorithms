/******************READ-ONLY PART BEGINS*****************/
#include <bits/stdc++.h>
using namespace std;
/*******************READ-ONLY PART ENDS******************/

/******************READ-ONLY PART BEGINS*****************/


const int SIZE = 200 ;
vector<int> lightBulbs(vector<int> states, vector<int> numbers){
	
	bool prime[SIZE + 1];
    memset(prime, true, sizeof(prime));
 
	int spf[SIZE];
    memset(spf, 0 , sizeof(spf));
 
    for (int p = 2; p * p <= SIZE; p++)
    {
        if (prime[p] == true)
        {
			spf[p] = p;
            for (int i = p * p; i <= SIZE; i += p){
                prime[i] = false;
				spf[i] = p;
			}
        }
		cout<<endl<<endl;
    }
	
	for(int i = 0 ; i < numbers.size() ; i++){
		int num = numbers[i];
		int curr = spf[num];	
		while(num != 1){
			global_arr[spf[num]] ^= 1;
			while(num % curr == 0)
				num /= curr;
		}
	}

	for(int i = 0 ; i < SIZE ; i++){
		if(spf[i] == i){
			if(global_arr[i]){
				for(int j = i-1 ; j < SIZE ; j += i){
					states[i] ^= 1;
				}
			}
		}
	}
	
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
