class Solution {
public:
int recursive(int n)
{
    if(n==0 || n==1)return 1;
    return climbStairs(n-1)+climbStairs(n-2);
}
int memoization(int n,vector<int>&dp)
{
    if(n==0 || n==1)return 1;
    if(dp[n]!=-1)return dp[n];
    dp[n]=memoization(n-1,dp)+memoization(n-2,dp);
    return dp[n];
}
int tabulation(int n)
{
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int spaceoptimized(int n)
{
    int prev1=1;
    int prev2=1;
    int curr=0;
    for(int i=2;i<=n;i++)
    {
        curr=prev2+prev1;
        prev1=prev2;
        prev2=curr;
    }
    return (curr==0)?1:curr;
}
    int climbStairs(int n) 
    {
        // vector<int>dp(n+1,-1);
        // return memoization(n,dp);
        return spaceoptimized(n);
    }
};