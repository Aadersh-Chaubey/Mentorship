// https://leetcode.com/problems/single-number-ii/
// TC= O(n)
// sc= O(1)
// in this solution i have created an array of size 33 to store bits of our array
// since every number occurs three times, so every bit should occur be 3*k number of times
// but since one number which occur only one times, we can easily identify it by finding which bit is not divisible by 3

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits[33]{0};
        for(int e : nums){
            int i = 0;
            if(e < 0) bits[32]++;
            while(e != 0){
                bits[i++] += e % 2;
                e /= 2;
            }
        }
        int ans = 0;
        for(int i = 0; i <= 31; i++){
            // if(bits[i]%3)cout << i << " "<<(1<<i)<<" "<< ((1<<i)*1)<< endl;
            if(bits[i]%3)ans += ( 1<<i ) * 1;
        }
        if(bits[32]%3){
            if(ans == INT_MIN)ans = 2147483648;
            else ans *= -1;
        }
            return ans;
    }
};