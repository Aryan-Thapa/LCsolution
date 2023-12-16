class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        if(m!=n) return false;
        int hash[256]={0};
        for(int i=0;i<s.size();i++)hash[s[i]]++;
        for(int i=0;i<t.size();i++)hash[t[i]]--;
        for(auto i:hash)
        {
            if(i!=0)return false;
        }
        return true;
    }
};