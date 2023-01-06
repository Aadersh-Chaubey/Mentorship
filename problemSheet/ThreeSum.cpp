// https://leetcode.com/problems/3sum/submissions/872523191/
// TC= O(n^2)
// SC = O(n^2)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int i = 0, n = arr.size(), j = n - 1;
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++){
            int s = i + 1, e = n - 1;
            if(i!=0 && arr[i-1] == arr[i])continue;
            while(s < e){
                if(arr[s] + arr[e] > -arr[i])e--;
                else if(arr[s] + arr[e] < -arr[i])s++;
                else{
                    if(s == i+1 || arr[s] != arr[s - 1])
                        ans.push_back({arr[i], arr[s], arr[e]});
                    s++;
                }
            }
        }
        return ans;

    }
};