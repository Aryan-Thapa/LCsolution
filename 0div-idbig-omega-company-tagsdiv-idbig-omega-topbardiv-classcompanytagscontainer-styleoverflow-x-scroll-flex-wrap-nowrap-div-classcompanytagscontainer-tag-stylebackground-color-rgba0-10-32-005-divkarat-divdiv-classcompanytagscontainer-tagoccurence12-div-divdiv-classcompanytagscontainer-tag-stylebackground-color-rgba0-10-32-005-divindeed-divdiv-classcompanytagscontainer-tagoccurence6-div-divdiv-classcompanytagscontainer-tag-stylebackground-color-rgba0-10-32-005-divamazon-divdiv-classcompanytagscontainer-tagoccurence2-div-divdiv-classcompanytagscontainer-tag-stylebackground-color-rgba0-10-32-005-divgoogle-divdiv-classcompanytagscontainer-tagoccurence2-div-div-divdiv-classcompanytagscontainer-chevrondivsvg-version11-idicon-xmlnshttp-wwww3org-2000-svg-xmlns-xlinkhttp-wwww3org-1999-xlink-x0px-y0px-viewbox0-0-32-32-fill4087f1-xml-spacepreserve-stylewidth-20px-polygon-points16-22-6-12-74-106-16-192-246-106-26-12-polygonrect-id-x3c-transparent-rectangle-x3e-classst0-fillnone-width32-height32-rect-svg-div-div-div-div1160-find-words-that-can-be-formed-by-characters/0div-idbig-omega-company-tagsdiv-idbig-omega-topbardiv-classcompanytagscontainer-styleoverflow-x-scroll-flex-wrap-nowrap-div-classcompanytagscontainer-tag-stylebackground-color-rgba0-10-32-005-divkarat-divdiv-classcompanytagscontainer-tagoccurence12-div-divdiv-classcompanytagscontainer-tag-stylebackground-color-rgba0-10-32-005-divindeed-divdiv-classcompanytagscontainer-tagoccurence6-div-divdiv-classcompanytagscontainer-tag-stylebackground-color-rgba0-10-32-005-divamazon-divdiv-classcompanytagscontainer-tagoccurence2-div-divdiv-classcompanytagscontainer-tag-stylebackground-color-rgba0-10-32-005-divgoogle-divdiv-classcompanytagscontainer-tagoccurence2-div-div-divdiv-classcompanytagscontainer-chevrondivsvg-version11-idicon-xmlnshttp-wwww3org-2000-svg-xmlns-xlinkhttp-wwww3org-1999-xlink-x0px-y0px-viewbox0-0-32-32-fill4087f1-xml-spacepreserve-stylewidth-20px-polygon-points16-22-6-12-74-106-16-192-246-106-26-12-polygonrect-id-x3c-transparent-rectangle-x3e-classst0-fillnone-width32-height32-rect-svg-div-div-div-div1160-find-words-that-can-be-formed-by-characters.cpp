class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int ans=0;
        int hash[256]={0};
        for(int i=0;i<chars.size();i++)
        {
            hash[chars[i]]++;
        }
        for(auto i: words)
        {
            int wordhash[256]={0};
            bool valid=true;
            for(auto j: i)
            {
                wordhash[j]++;
                if(wordhash[j]>hash[j])
                {
                    valid=false;
                    break;
                }
            }
            if(valid==true)
            {
                ans=ans+i.size();
            }
        }
        return ans;
    }
};