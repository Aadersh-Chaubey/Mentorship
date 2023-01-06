// link: https://leetcode.com/problems/two-sum/solutions/?orderBy=most_votes
// TC: O(nlogn) SC: O(n)
// with the help of hashing we can easily solve it in O(N) time complexity

class Solution {
public:
    struct ele{
        int i;
        int val;
    };
    static bool comp(struct ele a , ele b){
        if(a.val < b.val)return 1;
        else if(b.val < a.val)return 0;
        else return a.i < b.i;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<struct ele>arr(n);
        for(int i = 0; i < n; i++){
            struct ele a = {i, nums[i]};
            arr[i] = a;
        }
        sort(arr.begin(), arr.end(), comp);
        // for(auto e : arr)cout << e.val<< endl;
        int i = 0, j = n - 1;
        while(i < j){
            if(arr[i].val + arr[j].val > target)j--;
            else if(arr[i].val + arr[j].val < target)i++;
            else return {arr[i].i, arr[j].i};
        }
        return {};

    }
};