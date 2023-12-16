class Solution {
public:
int dpsolve(int n,vector<int>&dp)
{
    //basecase
    if(n==0 || n==1) return n;
    if(dp[n]!=-1) return dp[n];
    return dpsolve(n-1,dp)+dpsolve(n-2,dp);
}
    int fib(int n) 
    {
        //step1 create a dp array 
        vector<int>dp(n+1,-1);
        int ans=dpsolve(n,dp);
        return ans;
    }
};