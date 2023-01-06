// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// TC= O(log n)
// SC= O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), s = 0, e = n - 1, p;
        // smallest number
        while(s <= e){
            int m = (s + e) / 2;
            if(nums[m] >= nums[0]){
                s = m + 1;
            }else{
                if((m == 0 || nums[m - 1] > nums[m]) && (m == n - 1 || nums[m + 1] > nums[m])){
                    p = m;
                    break;
                }else{
                    e = m - 1;
                }
            }
        }
        // search for the number
        s = 0, e = n - 1;
        while (s <= e){
            int mid = (e + s) / 2;
            int realmid = (mid + p) % n;
            if(nums[realmid] == target)return realmid;
            else if(nums[realmid] < target) s = mid + 1;
            else e = mid - 1;
        }
        return -1;
    }
};

// to find the minimum number in the rotated array i found a better written code from leetcode comment

// int n = nums.size(), s = 0, e = n - 1, p;
// while(s < e){
//     int m = (s + e) / 2;
//     if(nums[m] > nums[e])s = m + 1;
//     else e = m;
// }

// when s equals the e that index is the index of smallest number
