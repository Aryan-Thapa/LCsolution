class Solution {
public:
void permutehelp(vector<int>& nums,vector<vector<int>>&ans,int i)
{
    if(i>=nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int j=i;j<nums.size();j++)
    {
        swap(nums[i],nums[j]);
        //rec call
        permutehelp(nums,ans,i+1);
        //backtrack
        swap(nums[i],nums[j]);
    }
}
    vector<vector<int>> permute(vector<int>& nums) 
    {
        int i=0;
        vector<vector<int>>ans;
        permutehelp(nums,ans,i);
        return ans;    
    }
};