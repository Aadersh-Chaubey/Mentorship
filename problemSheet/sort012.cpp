// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
// TC O(n)
// SC O(1)
class Solution
{
    public:
    void swap(int* a, int i, int j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    void sort012(int a[], int n)
    {
        // code here
        int i = 0;
        int j = n - 1;
        for(int k = 0; k <= j;){
            if(a[k] == 0)swap(a, k++, i++);
            else if(a[k] == 2)swap(a, k, j--);
            else k++;
        }
    }
    
    
};