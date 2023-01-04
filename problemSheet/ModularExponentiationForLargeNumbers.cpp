class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    if(n == 0)return 1;
		    long long int ans;
		   if(n%2){
		       ans = PowMod(x, n - 1, M);
		       ans *= x;
		       return ans % M;
		   }else{
		       ans = PowMod(x, n/2, M);
		       ans *= ans;
		       return ans%M;
		   }
		}
};