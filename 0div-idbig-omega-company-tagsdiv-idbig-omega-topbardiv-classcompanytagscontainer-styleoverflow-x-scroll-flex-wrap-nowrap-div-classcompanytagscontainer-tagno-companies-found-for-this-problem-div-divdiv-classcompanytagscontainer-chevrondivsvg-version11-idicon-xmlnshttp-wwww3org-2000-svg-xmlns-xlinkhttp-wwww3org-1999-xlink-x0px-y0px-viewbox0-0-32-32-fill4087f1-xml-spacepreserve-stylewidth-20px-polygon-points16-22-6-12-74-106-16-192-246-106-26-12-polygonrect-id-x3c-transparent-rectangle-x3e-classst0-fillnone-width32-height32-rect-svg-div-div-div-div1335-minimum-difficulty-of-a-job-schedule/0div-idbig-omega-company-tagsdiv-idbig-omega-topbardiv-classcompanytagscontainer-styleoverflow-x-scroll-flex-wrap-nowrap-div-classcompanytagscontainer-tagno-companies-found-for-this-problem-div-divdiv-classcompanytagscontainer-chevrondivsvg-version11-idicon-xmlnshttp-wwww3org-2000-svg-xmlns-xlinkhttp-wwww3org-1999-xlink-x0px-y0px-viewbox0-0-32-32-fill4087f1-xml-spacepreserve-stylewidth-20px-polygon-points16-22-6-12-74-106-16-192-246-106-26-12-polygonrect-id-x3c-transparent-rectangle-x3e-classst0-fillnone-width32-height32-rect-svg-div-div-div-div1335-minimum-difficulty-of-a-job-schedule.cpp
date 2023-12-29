class Solution {
public:
int solverec(vector<int>&jobDifficulty,int d,int i,int n)
{
    //basecase
    if(d==1)return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
    int maxi=INT_MIN;
    int curr=INT_MAX;
    for(int k=i;k<=n-d;k++)
    {
        maxi=max(maxi,jobDifficulty[k]);
        curr=min(curr,maxi+solverec(jobDifficulty,d-1,k+1,n));
    }
    return curr;
}
int solveusingmem(vector<int>&jobDifficulty,int d,int i,int n,vector<vector<int>>&dp)
{
    //basecase
    if(d==1)return *max_element(jobDifficulty.begin()+i,jobDifficulty.end());
    if(dp[i][d]!=-1)return dp[i][d];
    int maxi=INT_MIN;
    int curr=INT_MAX;
    for(int k=i;k<=n-d;k++)
    {
        maxi=max(maxi,jobDifficulty[k]);
        curr=min(curr,maxi+solveusingmem(jobDifficulty,d-1,k+1,n,dp));
    }
    dp[i][d]=curr;
    return dp[i][d];
}

    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        int n=jobDifficulty.size();
        if(n<d)return -1;
        // return solverec(jobDifficulty,d,0,n);
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        return solveusingmem(jobDifficulty,d,0,n,dp);
    }
};