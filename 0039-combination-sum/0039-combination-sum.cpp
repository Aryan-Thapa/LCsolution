class Solution {
public:
void solve(vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>output,int sum,int index)
{
    //base case
    if(sum==target)
    {
        ans.push_back(output);
        return;
    }
    for(int i=index;i<candidates.size();i++)
    {
        if(sum+candidates[i]<=target)
        {
            //store
            output.push_back(candidates[i]);
            //rec call
            solve(candidates,target,ans,output,sum+candidates[i],i);
            //backtrack
            output.pop_back();

        }

    }

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>ans;
        vector<int>output;
        int sum=0;
        int index=0;
        solve(candidates,target,ans,output,sum,index);
        return ans;
        
    }
};