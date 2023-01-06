//https://leetcode.com/problems/find-peak-element/description/

//TC= O(n)
//SC= O(1)

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++){
            if((i==0 || arr[i - 1] < arr[i]) && (i == arr.size() - 1 || arr[i + 1] < arr[i])){
                return i;
            }
        }
        return -1;
    }
};