class Solution {
public:
int solverecursion(vector<int>&nums,int n)
{
    if(n<0)return 0;
    if(n==0)return nums[0];
    int include=solverecursion(nums,n-2)+nums[n];
    int exclude=solverecursion(nums,n-1);
    return max(include,exclude);
}
int solveusingmem(vector<int>&nums,int n,vector<int>&dp)
{
    //base case
    if(n<0)return 0;
    if(n==0)return nums[0];
    //step3
    if(dp[n]!=-1)return dp[n];
    int include=solveusingmem(nums,n-2,dp)+nums[n];
    int exclude=solveusingmem(nums,n-1,dp);
    //step2
    dp[n]=max(include,exclude);
    return dp[n];
}
int solveusingtabulation(vector<int>&nums,int n)
{
    //step1
    vector<int>dp(n+1,0);
    dp[0]=nums[0];
    for(int i=1;i<=n;i++)
    {
        int temp=0;
        if(i-2>=0)
        {
            temp=dp[i-2];
        }
        int include=temp+nums[i];
        int exclude=dp[i-1]+0;
        dp[i]=max(include,exclude);
    }
    return dp[n];
}
    int rob(vector<int>& nums) 
    {
        int n=nums.size()-1;
        //return solverecursion(nums,n);
        // vector<int>dp(n+1,-1);
        // return solveusingmem(nums,n,dp);
        return solveusingtabulation(nums,n);
    }
};