class Solution {
public:
    string largestGoodInteger(string num) 
    {
        
        string finalans="";
        for(int i=0;i<num.size();i++)
        {
            string ans="";
            int j=i+1;
            int k=i+2;
            if(k<num.size() && num[i]==num[j] && num[j]==num[k])
            {
                ans=ans+num[i]+num[j]+num[k];
            }
            if(ans>finalans)
            {
                finalans=ans;
            }
        } 
        return finalans;   
    }
};