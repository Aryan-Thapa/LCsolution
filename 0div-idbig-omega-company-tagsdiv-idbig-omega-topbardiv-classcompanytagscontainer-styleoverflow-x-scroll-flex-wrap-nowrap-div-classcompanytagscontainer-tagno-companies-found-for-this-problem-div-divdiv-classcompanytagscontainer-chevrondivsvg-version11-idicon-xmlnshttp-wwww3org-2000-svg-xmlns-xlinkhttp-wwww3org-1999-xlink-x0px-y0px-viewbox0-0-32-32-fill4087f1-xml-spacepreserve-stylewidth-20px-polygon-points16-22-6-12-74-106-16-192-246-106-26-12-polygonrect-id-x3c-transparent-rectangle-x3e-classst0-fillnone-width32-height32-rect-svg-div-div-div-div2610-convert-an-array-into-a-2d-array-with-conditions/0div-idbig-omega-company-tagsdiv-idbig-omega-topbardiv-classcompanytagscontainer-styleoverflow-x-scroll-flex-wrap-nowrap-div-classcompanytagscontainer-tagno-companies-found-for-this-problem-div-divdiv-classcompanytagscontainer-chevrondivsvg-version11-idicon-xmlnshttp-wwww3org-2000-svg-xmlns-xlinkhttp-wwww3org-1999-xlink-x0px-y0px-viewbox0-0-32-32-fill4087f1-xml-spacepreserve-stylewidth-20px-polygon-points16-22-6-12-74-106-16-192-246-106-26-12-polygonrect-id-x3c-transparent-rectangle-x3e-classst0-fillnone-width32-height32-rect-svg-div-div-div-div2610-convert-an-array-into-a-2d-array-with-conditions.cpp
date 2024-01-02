class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        //map to store the frequency of each element
        unordered_map<int,int>nmap;
        for(auto i:nums)
        {
            nmap[i]++;
            if(nmap[i]>ans.size())
            {
                ans.push_back({});
            }
            ans[nmap[i]-1].push_back(i);
        }
        return ans;

        
    }
};