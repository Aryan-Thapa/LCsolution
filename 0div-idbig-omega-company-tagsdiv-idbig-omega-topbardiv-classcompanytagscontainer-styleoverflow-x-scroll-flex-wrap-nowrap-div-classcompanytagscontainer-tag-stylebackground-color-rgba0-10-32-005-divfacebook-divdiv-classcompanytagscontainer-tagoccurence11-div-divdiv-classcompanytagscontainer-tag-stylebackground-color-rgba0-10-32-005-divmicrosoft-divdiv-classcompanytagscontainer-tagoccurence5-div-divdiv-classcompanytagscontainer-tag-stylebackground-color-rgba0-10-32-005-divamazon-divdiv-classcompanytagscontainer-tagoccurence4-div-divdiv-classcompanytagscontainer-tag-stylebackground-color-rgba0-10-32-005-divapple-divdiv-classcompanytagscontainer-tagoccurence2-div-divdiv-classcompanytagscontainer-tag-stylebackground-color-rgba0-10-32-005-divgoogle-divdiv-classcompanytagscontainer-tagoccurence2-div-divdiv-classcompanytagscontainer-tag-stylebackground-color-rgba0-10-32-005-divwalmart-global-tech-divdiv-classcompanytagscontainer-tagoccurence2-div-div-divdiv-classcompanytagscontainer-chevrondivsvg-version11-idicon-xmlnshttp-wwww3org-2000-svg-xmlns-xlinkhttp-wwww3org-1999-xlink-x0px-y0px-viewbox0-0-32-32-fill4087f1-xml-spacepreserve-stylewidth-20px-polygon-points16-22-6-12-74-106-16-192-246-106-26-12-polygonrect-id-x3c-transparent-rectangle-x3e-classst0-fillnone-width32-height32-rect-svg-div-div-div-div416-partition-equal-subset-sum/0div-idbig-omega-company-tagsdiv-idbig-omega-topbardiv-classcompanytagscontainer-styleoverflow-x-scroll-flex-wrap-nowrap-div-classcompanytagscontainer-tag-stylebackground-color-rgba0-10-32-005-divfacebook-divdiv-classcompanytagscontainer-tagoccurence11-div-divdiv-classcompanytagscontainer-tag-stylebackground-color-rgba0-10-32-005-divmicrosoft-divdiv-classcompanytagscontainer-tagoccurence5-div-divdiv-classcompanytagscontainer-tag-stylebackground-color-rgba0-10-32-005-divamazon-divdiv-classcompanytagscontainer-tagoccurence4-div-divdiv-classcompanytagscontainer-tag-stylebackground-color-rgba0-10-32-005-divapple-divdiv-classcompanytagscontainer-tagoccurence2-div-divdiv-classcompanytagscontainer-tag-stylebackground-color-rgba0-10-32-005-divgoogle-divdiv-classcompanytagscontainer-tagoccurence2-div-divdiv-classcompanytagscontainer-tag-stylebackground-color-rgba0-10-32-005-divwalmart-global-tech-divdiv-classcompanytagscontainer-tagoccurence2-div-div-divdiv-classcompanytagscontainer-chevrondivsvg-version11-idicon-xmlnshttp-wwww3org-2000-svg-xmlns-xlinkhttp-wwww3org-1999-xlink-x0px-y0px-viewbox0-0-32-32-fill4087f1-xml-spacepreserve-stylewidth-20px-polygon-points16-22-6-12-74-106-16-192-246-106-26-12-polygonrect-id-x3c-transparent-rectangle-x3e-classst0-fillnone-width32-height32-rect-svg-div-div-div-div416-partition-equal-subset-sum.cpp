class Solution {
public:
bool recursivesolution(vector<int>&nums,int index,int target)
{
    if(index>=nums.size())return 0;
    if(target<0)return 0;
    if(target==0)return 1;

    bool include=recursivesolution(nums,index+1,target-nums[index]);
    bool exclude=recursivesolution(nums,index+1,target);
    return (include || exclude);
}
bool memsolve(vector<int>&nums,int index,int target,vector<vector<int>>&dp)
{
    if(index>=nums.size())return 0;
    if(target<0)return 0;
    if(target==0)return 1;
    if(dp[index][target]!=-1)return dp[index][target];
    bool include=memsolve(nums,index+1,target-nums[index],dp);
    bool exclude=memsolve(nums,index+1,target,dp);
    dp[index][target]=(include || exclude);
    return dp[index][target];
}
bool tabulation(vector<int>&nums,int index,int target)
{
    vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));
    for(int i=0;i<nums.size();i++)
    {
        dp[i][0]=1;
    }
    for(int i=nums.size()-1;i>=0;i--)
    {
        for(int j=1;j<=target;j++)
        {
            bool include=0;
            if(j-nums[i]>=0)
            {
                include=dp[i+1][j-nums[i]];
            }
            bool exclude=dp[i+1][j];
            dp[i][j]=(include||exclude);
        }
    }
    return dp[index][target];
}
bool spaceoptimized(vector<int>&nums,int index,int target)
{
    vector<int>curr(target+1,0);
    vector<int>next(target+1,0);
    for(int i=0;i<nums.size();i++)
    {
        next[0]=1;
    }
    for(int i=nums.size()-1;i>=0;i--)
    {
        for(int j=1;j<=target;j++)
        {
            bool include=0;
            if(j-nums[i]>=0)
            {
                include=next[j-nums[i]];
            }
            bool exclude=next[j];
            curr[j]=(include||exclude);
        }
        next=curr;
    }
    return curr[target];
}

    bool canPartition(vector<int>& nums) 
    {
        int sum=0;
        for(auto i:nums)
        {
            sum+=i;
        }
        if(sum%2!=0)return false;
        int index=0;
        int target=sum/2;
        // return recursivesolution(nums,index,target);
        int n=nums.size();
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return spaceoptimized(nums,index,target);
    }
};