class Solution {
public:
    int totalMoney(int n) 
    {
        int numofweeks=n/7;
        int a=28;
        int sum=(numofweeks)*(2*a+(numofweeks-1)*7)/2;
        int remdays=n%7;
        for(int i=0;i<remdays;i++)
        {
            sum=sum+(numofweeks+1)+i;
        }
        return sum;
    }
};