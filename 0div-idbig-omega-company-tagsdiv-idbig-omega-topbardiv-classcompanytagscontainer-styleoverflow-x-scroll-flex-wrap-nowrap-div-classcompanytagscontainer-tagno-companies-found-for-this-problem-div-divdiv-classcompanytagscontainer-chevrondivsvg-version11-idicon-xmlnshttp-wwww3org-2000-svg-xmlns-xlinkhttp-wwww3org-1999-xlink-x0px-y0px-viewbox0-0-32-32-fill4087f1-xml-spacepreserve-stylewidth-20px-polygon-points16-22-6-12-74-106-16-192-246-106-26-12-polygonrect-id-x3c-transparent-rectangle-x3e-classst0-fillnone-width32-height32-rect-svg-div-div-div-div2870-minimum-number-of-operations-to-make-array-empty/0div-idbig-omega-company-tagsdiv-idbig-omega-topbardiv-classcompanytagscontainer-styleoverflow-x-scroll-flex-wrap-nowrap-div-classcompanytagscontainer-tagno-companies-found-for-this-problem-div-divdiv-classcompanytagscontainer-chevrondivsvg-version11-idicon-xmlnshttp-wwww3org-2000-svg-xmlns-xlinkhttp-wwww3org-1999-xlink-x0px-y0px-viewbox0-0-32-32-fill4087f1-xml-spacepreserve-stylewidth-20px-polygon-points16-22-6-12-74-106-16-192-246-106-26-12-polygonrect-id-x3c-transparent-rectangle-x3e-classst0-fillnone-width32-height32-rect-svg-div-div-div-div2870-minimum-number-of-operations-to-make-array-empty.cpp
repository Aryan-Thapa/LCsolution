class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int ans=0;
        unordered_map<int,int>count;
        for(int i=0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(count[nums[i]]==1)
            {
                ans=-1;
                break;
            }
            else if(count[nums[i]]%3==0)
            {
                ans=ans+(count[nums[i]]/3);
                count[nums[i]]=0;
            }
            else if(count[nums[i]]%3==2 || count[nums[i]]%3==1)
            {
                ans=ans+(count[nums[i]]/3)+1;
                count[nums[i]]=0;
            }
        }
        return ans;        
    }
};