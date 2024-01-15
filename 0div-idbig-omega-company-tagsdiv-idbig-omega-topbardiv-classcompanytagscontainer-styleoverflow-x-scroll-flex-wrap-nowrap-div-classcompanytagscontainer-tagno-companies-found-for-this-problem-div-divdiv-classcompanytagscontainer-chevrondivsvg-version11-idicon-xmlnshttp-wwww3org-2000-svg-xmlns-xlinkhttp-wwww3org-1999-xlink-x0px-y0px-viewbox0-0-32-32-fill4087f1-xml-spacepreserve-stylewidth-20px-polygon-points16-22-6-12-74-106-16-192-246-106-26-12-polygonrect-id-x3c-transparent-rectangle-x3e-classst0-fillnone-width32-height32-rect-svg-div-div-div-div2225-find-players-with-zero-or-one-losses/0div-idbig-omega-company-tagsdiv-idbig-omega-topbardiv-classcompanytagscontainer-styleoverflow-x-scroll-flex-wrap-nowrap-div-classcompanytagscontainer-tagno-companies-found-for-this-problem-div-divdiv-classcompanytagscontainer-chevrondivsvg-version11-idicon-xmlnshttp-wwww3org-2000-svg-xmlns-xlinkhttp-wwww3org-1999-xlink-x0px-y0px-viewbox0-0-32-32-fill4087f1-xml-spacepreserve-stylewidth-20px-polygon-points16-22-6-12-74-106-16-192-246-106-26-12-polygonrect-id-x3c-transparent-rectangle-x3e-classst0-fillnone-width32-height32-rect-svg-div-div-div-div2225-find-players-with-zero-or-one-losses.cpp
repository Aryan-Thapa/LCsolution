class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) 
    {
        map<int,int>mp;
        for(auto i:matches)
        {
            int w=i[0];
            int l=i[1];
            if(mp.find(w)==mp.end())mp[w]=0;
            mp[l]++;
        }
        vector<int>warr,larr;
        for(auto i:mp)
        {
            if(i.second==0)warr.push_back(i.first);
            else if(i.second==1)larr.push_back(i.first);
        }
        return {warr,larr};   
    }
};