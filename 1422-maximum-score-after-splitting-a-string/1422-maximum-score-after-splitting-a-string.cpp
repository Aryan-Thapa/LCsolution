class Solution {
public:
    int maxScore(string s) 
    {
        int countzeros=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]-'0'==0)countzeros++;
            int countones=0;
            for(int j=i+1;j<s.size();j++)
            {
                if(s[j]-'0'==1)countones++;
            }
            int sum=countzeros+countones;
            ans=max(ans,sum);
        }
        return ans;
    }
};