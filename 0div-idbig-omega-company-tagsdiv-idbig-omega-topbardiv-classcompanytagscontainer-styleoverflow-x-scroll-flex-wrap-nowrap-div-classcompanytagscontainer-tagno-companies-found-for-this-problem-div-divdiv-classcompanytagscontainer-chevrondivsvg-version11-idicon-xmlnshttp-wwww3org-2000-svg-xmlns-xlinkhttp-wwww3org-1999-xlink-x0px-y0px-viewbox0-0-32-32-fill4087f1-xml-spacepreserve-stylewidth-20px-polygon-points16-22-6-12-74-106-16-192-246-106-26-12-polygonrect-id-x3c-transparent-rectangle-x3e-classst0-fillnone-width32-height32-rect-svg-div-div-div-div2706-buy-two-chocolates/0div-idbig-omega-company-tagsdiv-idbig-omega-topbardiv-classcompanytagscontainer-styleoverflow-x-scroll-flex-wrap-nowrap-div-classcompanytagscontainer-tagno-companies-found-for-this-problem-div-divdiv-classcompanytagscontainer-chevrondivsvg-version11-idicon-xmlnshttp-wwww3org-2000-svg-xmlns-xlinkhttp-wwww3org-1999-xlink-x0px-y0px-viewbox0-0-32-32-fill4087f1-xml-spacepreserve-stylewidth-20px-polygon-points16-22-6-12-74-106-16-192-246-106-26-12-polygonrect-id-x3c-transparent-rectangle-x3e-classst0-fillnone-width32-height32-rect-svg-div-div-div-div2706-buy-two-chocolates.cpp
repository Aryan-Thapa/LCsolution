class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        sort(prices.begin(),prices.end());
        int i=0,j=i+1;
        if(prices[i]+prices[j]>money) return money;
        return money-(prices[i]+prices[j]);  
    }
};