#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    while(t-- != 0){
        int n,m,a;
        cin >> m >> n;
        int mod[n]={0};
        for(int i = 0; i < m; i++){
            cin >> a;
            mod[a % n]++;
        }
        int un = 0, dis = 0;
        for(int i = 0; i < n; i++){
            if(mod[i])dis++;
            if(mod[i] == 1)un++;
        }
        cout << dis<<endl<<un<<endl;
    }
    return 0;
}
