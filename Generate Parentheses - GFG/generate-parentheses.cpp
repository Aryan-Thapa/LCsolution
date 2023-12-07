//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(vector<string>&ans,string output,int open,int close)
    {
        //base case
        if(open==0 && close==0)
        {
            ans.push_back(output);
            return;
        
        }
        //include open
        if(open>0)
        {
            output.push_back('(');
            //rec call
            solve(ans,output,open-1,close);
            //backtrack
            output.pop_back();
        
        }
        //include close
        if(close>open)
        {
            output.push_back(')');
            solve(ans,output,open,close-1);
            output.pop_back();
            
        }
}
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string>ans;
        string output="";
        int open=n;
        int close=n;
        solve(ans,output,open,close);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends