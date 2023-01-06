class Solution {
public:
    bool isPalindrome(int x) {
        long long rev = 0, a = x;
        if(x < 0)return 0;
        while(a != 0){
            rev = rev * 10 + a % 10;
            a /= 10;
        }
        cout << rev << endl;
        if(rev == x)return 1;
        else return 0;
    }
};