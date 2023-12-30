//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int capacity,int wt[],int val[],int index)
    {
        //basecase
        if(index==0){
            if(wt[0]<=capacity)return val[0];
            else return 0;
        }
        int include=0;
        if(wt[index]<=capacity)
        {
            include=val[index]+solve(capacity-wt[index],wt,val,index-1);
        }
        int exclude=solve(capacity,wt,val,index-1);
        return max(include,exclude);
    }
    
    int solveusingmem(int capacity,int weight[], int value[], int index,vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(weight[0]<=capacity)return value[0];
            else return 0;
            
        }
        if(dp[index][capacity]!=-1)return dp[index][capacity];
        int include=0;
        if(weight[index]<=capacity)
        {
            include=value[index]+solveusingmem(capacity-weight[index],weight,value,index-1,dp);
            
        }
        int exclude=solveusingmem(capacity,weight,value,index-1,dp);
        dp[index][capacity]=max(include,exclude);
        return dp[index][capacity];
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
       return solveusingmem(W,wt,val,n-1,dp);
    //   return solve(W,wt,val,n-1);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends