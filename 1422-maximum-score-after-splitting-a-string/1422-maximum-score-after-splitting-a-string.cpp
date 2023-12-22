class Solution {
public:
    int maxScore(string s) 
    {
        int ones=0;
        int zeros=0;
        int ans=0;
        for(auto i:s)
        {
            if(i-'0'==1)ones++;
        }
        for(int j=0;j<s.size()-1;j++)
        {
            if(s[j]-'0'==0)zeros++;
            else ones--;
            ans=max(ans,ones+zeros);
        }
        return ans;
        
    }
};