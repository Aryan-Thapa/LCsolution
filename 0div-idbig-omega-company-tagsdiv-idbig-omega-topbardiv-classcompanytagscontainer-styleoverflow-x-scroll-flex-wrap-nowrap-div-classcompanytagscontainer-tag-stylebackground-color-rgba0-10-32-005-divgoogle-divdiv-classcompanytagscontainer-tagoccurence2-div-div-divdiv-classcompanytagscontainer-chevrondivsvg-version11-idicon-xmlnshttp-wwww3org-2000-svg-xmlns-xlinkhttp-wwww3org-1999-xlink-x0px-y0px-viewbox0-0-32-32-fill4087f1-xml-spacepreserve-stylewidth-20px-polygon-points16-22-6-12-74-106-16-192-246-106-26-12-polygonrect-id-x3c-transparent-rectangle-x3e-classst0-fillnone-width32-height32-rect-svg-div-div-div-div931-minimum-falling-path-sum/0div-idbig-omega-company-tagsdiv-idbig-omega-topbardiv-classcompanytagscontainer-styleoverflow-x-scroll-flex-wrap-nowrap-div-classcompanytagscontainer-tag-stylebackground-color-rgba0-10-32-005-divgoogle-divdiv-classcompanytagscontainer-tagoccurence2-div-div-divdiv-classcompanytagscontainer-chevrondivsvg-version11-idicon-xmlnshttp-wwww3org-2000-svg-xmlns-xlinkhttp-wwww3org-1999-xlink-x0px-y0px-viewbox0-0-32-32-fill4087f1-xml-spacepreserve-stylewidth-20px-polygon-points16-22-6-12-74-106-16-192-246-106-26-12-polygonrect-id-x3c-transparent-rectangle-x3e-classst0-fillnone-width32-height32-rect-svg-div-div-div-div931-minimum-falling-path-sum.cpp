class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        //base case
        for(int i=0;i<m;i++) dp[0][i]=matrix[0][i];
        //handling rest of the rows
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mini=INT_MAX;
                //checking all its parent value for minimum value
                mini=min(mini,dp[i-1][j]);
                if(j-1>=0) mini=min(mini,dp[i-1][j-1]);
                if(j+1<m) mini=min(mini,dp[i-1][j+1]);
                dp[i][j]=mini+matrix[i][j];
            }
        }
        // all possible sum stored in the last row 
        int ans=INT_MAX;
        // fetching the minimum last sum from the last row
        for(int i=0;i<m;i++) ans=min(ans,dp[n-1][i]);
        return ans;
    }
};