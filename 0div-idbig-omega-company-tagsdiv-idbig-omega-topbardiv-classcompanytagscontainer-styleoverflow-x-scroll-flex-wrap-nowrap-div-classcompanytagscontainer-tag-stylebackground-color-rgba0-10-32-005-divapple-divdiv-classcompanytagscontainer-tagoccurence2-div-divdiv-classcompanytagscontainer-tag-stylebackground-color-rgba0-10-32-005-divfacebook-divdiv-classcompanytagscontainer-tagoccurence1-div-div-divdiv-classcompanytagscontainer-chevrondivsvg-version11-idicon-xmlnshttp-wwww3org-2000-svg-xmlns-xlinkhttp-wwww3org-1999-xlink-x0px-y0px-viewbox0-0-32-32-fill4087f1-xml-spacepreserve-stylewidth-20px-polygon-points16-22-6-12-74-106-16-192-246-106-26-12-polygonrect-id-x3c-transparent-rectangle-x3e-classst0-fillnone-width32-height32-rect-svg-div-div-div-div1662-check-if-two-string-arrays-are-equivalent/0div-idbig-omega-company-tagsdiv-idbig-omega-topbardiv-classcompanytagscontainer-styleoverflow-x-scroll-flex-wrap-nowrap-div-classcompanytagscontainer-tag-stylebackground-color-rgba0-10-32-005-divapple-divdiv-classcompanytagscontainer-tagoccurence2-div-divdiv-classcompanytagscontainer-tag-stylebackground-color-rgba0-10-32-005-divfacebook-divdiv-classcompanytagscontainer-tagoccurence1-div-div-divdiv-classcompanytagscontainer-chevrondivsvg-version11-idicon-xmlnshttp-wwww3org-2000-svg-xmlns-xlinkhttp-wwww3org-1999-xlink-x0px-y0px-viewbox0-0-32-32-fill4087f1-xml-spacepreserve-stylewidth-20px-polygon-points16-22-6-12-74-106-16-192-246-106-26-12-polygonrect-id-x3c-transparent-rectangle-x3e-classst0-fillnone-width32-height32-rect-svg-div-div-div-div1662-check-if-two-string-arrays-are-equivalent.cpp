class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        vector<char>ans;
        vector<char>ans2;
        for(auto i:word1)
        {
            for(auto j:i)
            {
                ans.push_back(j);
            }
        }
        for(auto i:word2)
        {
            for(auto j:i)
            {
                ans2.push_back(j);
            }
        }
        int n1=ans.size();
        int n2=ans2.size();
        if(n1!=n2)
        {
            return false;
        }
        for(int i=0;i<n1;i++)
        {
            if(ans[i]!=ans2[i])
            {
                return false;
            }
        }
        return true;
        
    }
};