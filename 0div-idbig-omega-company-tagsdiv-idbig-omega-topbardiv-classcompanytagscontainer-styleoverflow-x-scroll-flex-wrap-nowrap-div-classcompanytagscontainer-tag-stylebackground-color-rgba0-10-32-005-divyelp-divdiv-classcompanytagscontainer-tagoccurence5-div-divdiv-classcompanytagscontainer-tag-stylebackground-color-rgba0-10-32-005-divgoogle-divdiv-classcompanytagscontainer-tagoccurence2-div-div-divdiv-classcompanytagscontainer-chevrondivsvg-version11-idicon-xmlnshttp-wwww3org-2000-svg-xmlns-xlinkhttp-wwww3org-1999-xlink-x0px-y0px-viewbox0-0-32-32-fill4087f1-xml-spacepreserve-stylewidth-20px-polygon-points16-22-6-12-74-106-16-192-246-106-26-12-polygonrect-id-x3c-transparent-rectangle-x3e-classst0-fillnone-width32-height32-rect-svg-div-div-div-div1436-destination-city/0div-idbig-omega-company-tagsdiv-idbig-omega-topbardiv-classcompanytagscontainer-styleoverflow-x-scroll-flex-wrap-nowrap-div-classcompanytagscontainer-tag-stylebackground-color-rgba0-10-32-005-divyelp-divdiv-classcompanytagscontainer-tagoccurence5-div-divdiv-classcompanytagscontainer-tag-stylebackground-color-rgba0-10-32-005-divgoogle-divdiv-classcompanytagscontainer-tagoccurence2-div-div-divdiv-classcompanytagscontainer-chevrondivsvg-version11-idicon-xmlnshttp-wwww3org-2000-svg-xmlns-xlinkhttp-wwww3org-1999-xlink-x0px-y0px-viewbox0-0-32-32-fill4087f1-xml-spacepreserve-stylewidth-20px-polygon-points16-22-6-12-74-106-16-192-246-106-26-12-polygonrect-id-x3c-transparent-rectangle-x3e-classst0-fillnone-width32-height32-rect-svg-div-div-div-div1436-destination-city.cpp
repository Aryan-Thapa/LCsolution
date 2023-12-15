class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        unordered_set<string>start;
        for(auto i:paths)
        {
            //inserting the starting cities into the set
            start.insert(i[0]);
        }
        for(auto i:paths)
        {
            if(start.find(i[1])==start.end())
            {
                return i[1];
            }
        }
        return "";
        
    }
};