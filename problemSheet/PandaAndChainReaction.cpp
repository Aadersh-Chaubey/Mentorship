#include <iostream>
using namespace std;
int mod = 1000003;
int ans(long long int x ,long long int n, int* fact){
	if(n >= mod || x == 0)return 0;
	else return ((long long int)fact[n]*x)%mod;
}
int main() {
	int t;
	cin >> t;
	int fact[1000003];
	fact[0] = 1;
	for(int i = 1; i < 1000003; i++){
		fact[i] = ((long long int)i * (long long int)fact[i - 1]) % mod;
	}
	while(t--){
		long long int n,x;
		cin >> n >> x;
		cout << ans(x%mod, n, fact) << endl;
	}
}