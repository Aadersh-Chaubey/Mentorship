// https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/stringify-2-304b51ea/
//TC = O(n)
//SC = O(1)
// this was a challenging problem for me, so may attemps!, finally did it with a simple approach.
// first if zero is less than required, than start from index 0 and change every number which are in surplus into zero
// after zero, go for two, if 2 < req[2], start from last index and change every number which are in surplus into two
// then if count[0] > req[0], start from last index and change 0 into 1 untill count[0] > req[0]
// then untill count[0] > req[2], start from 0 index and change 2 into 1
#include <iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t-- != 0){
		int n, req[3], count[3] = {0}, ans = 0;
		string s;
		cin >> n >> req[0] >> req[1] >> s;
		req[2] = n - req[0] - req[1];

		for(int i = 0; i < n; i++){
			count[s[i] - '0']++;
		}
		// cout << count[2]<< endl;
		int i = 0;
		while(count[0] < req[0]){
			int ch = s[i] - '0';
			if(count[ch] > req[ch]){
				ans++;
				s[i] = '0';
				count[ch]--, count[0]++;
			}
			i++;
		}

		i = n - 1;
		while(count[2] < req[2]){
			int ch = s[i] - '0';
			if(count[ch] > req[ch]){
				ans++;
				s[i] = '2';
				count[ch]--, count[2]++;
			}
			i--;
		}
		i = n - 1;
		// cout << req[2] <<" " <<count[2]<<endl;
		while(count[0] > req[0]){
			int ch = s[i] - '0';
			if(ch == 0){
				ans++;
				s[i] = '1';
				count[0]--, count[1]++;
			}
			i--;
		}
		i = 0;
		while(count[2] > req[2]){
			int ch = s[i] - '0';
			if(ch == 2){
				ans++;
				s[i] = '1';
				count[2]--, count[1]++;
			}
			i++;
		}

		cout << ans<< endl;
		cout << s << endl;
	}
}