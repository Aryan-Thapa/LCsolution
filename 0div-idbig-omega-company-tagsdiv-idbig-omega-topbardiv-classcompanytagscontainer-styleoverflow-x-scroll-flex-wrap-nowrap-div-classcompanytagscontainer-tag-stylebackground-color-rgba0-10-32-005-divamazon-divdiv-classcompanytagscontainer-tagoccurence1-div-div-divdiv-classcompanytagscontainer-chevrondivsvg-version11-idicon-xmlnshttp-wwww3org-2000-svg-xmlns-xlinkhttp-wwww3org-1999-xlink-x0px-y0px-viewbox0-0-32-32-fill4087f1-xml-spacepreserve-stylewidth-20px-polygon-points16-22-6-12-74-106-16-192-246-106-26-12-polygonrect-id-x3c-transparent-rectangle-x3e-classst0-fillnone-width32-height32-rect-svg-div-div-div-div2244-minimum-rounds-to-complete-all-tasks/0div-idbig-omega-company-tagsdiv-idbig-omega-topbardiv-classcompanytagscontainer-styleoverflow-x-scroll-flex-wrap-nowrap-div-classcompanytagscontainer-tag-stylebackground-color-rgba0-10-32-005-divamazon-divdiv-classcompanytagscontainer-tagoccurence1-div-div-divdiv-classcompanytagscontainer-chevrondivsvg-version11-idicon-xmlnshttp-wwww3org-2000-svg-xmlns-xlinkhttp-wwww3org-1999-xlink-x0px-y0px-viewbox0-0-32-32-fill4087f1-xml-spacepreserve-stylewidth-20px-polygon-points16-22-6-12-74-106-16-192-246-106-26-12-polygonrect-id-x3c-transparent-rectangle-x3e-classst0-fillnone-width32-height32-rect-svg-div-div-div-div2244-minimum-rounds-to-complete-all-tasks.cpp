class Solution {
public:
    int minimumRounds(vector<int>& tasks) 
    {
        int ans=0;
        unordered_map<int,int>count;
        for(int i=0;i<tasks.size();i++)
        {
            count[tasks[i]]++;
        }
        for(int i=0;i<tasks.size();i++)
        {
            if(count[tasks[i]]==1)
            {
                ans=-1;
                break;
            }
            else if(count[tasks[i]]%3==0)
            {
                ans=ans+(count[tasks[i]]/3);
                count[tasks[i]]=0;
            }
            else if(count[tasks[i]]%3==1 || count[tasks[i]]%3==2)
            {
                ans=ans+(count[tasks[i]]/3)+1;
                count[tasks[i]]=0;
            }
        }
        return ans;
    }
};