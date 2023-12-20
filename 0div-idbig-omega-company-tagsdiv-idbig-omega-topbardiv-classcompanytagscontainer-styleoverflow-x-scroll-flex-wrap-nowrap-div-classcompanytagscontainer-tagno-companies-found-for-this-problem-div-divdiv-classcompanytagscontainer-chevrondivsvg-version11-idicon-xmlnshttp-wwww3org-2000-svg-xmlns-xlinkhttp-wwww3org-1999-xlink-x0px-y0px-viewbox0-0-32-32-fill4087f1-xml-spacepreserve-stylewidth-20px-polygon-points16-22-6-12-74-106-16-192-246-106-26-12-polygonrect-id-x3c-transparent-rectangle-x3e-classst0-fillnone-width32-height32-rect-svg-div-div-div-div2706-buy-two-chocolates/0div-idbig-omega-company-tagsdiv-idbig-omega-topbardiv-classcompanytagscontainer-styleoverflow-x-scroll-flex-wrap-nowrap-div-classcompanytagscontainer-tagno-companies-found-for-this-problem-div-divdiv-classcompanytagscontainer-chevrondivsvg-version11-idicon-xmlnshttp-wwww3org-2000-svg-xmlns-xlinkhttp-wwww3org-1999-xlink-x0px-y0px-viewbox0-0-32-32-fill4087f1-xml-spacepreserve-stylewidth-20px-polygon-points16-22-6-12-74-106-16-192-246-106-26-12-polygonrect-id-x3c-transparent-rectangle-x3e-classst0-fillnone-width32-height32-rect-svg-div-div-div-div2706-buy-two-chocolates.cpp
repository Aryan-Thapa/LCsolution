class Solution {
public:
    int buyChoco(vector<int>& prices, int money) 
    {
        sort(prices.begin(),prices.end());
        int i=0;
        int j=i+1;
        int cost=prices[i]+prices[j];
        if(cost>money) return money;
        return money-cost; 
         
    }
};