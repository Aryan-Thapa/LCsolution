class Solution {
public:
    bool isPathCrossing(string path) 
    {
        vector<int>patharr(2,0);
        map<vector<int>,int>mp;
        mp[patharr]++;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='N')
            {
                patharr[1]++;
            }
            else if(path[i]=='S')
            {
                patharr[1]--; 
            }
            else if(path[i]=='E')
            {
                patharr[0]++;
            }
            else if(path[i]=='W')
            {
                patharr[0]--;
            }
            if(mp.find(patharr)!=mp.end())
            {
                return true;
            }
            else
            {
                mp[patharr]++;
            }

        }
        return false;
    }
};