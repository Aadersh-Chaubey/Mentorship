#include <iostream>
using namespace std;
int main() {
	int n, a, count = 1;
	cin >> n;    
	long long sum = 0, preSum[n];
	for(int i = 0; i < n; i++){
		cin >> a;
		sum += a;
		preSum[i] = sum;
		int nextRange = (count + 1)*(count + 2)/2;
		if(nextRange == i + 1)count++;
	}
	long long max = -999999999;
	for(int i = 0; i < n; i++){
		int frontNum = n - i;
		int range = (count)*(count + 1) / 2;
		if(range > frontNum){
			count--;
			range = count*(count + 1)/ 2;
		}
		sum = preSum[i + range - 1];
		if(i != 0)sum -= preSum[i - 1];
		if(sum > max)max = sum;
	}
	cout << max << endl;
}