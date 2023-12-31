class Solution {
public:
int mincosthelper(vector<int>& days, vector<int>& costs,int i)
{
    //basecase
    if(i>=days.size())
    {
        return 0;
    }
    //1 day pass
    int cost1=costs[0]+mincosthelper(days,costs,i+1);
    
    //7 day pass
    int endpassday=days[i]+7-1;
    int j=i;
    while(j<days.size() && days[j]<=endpassday)
    {
        j++;
    }
    int cost7=costs[1]+mincosthelper(days,costs,j);
    //30 day pass
    endpassday=days[i]+30-1;
    j=i;
    while(j<days.size() && days[j]<=endpassday)
    {
        j++;
    }
    int cost30=costs[2]+mincosthelper(days,costs,j);
    return min(cost1,min(cost7,cost30));

}
int mincosthelpermem(vector<int>& days, vector<int>& costs,int i,vector<int>&dp)
{
    //basecase
    if(i>=days.size())
    {
        return 0;
    }
    if(dp[i]!=-1)return dp[i];
    //1 day pass
    int cost1=costs[0]+mincosthelpermem(days,costs,i+1,dp);
    
    //7 day pass
    int endpassday=days[i]+7-1;
    int j=i;
    while(j<days.size() && days[j]<=endpassday)
    {
        j++;
    }
    int cost7=costs[1]+mincosthelpermem(days,costs,j,dp);
    //30 day pass
    endpassday=days[i]+30-1;
    j=i;
    while(j<days.size() && days[j]<=endpassday)
    {
        j++;
    }
    int cost30=costs[2]+mincosthelpermem(days,costs,j,dp);
    dp[i]=min(cost1,min(cost7,cost30));
    return dp[i];
}
int tabulation(vector<int>& days, vector<int>& costs)
{
    int n=days.size();
    vector<int>dp(n+1,-1);
    dp[n]=0;
    for(int i=n-1;i>=0;i--)
    {
        int cost1=costs[0]+dp[i+1];
        //7 day pass
        int endpassday=days[i]+7-1;
        int j=i;
        while(j<days.size() && days[j]<=endpassday)
        {
            j++;
        }
        int cost7=costs[1]+dp[j];
        //30 day pass
        endpassday=days[i]+30-1;
        j=i;
        while(j<days.size() && days[j]<=endpassday)
        {
            j++;
        }
        int cost30=costs[2]+dp[j];
        dp[i]=min(cost1,min(cost7,cost30));
    }
    return dp[0];
}
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        // int n=days.size();
        // vector<int>dp(n+1,-1);
        return tabulation(days,costs);  
    }
};