//link : https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
// TC: O(n)
// SC: O(1)
// since there is only one number missing from 1 to n, i just found the sum of all numbers 1 to n i.e. n * (n + 1) / 2
//and the subtracted it from the sum of the given array
// the result of the substraction is the required number

class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        long long int sum = 0, reqSum = (long long int)(n + 1)*(long long int)(n) / 2;
        for(auto e : array)sum += e;
        return reqSum - sum;
    }
};