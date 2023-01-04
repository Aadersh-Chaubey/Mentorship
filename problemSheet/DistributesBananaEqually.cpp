#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	int primes[1000003] = {0};
	primes[0] = primes[1] = 0;
	for(int i = 2; i * i< 1000003; i++){
		if(primes[i] != 0)continue;
		for(int j = i * i; j < 1000003; j += i){
			primes[j] = 1; 
		}
	}
	while(t-- != 0){
		int n;
		cin >> n;
		if(!primes[n])cout <<"No"<<endl;
		else cout << "Yes"<<endl;
	}
}