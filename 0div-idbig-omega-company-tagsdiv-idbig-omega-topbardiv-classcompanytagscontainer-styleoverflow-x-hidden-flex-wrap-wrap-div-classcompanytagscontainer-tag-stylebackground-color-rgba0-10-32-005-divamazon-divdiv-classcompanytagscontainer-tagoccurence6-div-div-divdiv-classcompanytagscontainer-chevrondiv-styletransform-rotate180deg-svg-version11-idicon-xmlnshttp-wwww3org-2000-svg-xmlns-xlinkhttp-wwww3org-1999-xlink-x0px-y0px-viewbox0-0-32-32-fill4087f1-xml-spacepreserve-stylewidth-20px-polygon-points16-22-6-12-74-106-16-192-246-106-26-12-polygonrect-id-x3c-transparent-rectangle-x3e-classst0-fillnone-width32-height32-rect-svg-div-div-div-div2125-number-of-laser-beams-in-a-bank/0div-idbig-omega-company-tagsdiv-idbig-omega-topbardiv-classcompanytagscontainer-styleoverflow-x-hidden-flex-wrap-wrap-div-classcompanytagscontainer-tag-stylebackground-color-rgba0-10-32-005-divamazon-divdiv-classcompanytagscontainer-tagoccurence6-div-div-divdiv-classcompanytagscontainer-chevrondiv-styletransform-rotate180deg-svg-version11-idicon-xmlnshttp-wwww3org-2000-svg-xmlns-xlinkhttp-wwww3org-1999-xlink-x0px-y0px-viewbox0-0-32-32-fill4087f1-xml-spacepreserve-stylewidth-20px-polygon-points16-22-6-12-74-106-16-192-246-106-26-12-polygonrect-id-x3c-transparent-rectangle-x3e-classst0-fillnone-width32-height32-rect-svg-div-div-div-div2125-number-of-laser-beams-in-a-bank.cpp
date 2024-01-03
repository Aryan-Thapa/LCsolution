class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int prev=0;
        int ans=0;
        for(auto i:bank)
        {
            int count=0;
            for(auto c:i)
            {
                if(c=='1')count++;
            }
            if(count!=0)
            {
                ans=ans+(prev*count);
                prev=count;
            }
        }
        return ans;
        
        
    }
};