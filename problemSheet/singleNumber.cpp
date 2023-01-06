class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto e : nums)x ^= e;
        return x;
    }
};