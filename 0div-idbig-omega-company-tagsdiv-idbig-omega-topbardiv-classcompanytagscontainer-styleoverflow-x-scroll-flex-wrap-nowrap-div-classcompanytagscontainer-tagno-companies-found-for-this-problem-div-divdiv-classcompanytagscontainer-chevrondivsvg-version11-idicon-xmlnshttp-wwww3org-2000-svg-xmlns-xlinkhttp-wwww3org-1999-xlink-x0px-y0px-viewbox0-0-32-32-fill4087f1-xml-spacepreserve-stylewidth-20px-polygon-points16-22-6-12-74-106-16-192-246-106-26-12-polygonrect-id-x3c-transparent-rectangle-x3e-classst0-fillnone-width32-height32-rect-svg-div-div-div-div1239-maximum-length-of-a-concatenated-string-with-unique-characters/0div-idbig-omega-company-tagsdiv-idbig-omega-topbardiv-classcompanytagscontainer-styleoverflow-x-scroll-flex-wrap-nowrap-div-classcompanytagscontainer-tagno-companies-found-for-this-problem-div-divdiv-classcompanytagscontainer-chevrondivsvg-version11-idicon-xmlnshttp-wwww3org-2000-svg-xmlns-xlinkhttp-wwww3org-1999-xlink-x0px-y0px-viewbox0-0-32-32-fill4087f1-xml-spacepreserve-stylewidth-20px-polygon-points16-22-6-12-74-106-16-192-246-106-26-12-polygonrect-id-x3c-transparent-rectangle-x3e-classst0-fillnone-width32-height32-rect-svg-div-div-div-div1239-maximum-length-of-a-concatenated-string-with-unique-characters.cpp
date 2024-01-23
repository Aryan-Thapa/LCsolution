class Solution {
public:
    int maxLength(vector<string>& arr) 
    {
        return solve(arr,0,"");
    }
    private:
    int solve(vector<string>&arr,int i,string ans)
    {
        unordered_set<char>ansset(ans.begin(),ans.end());
        //basecase
        if(ans.size()!=ansset.size())return 0;
        if(i>=arr.size())return ans.size();
        int best=ans.size();
        // include
        best=max(best,solve(arr,i+1,ans+arr[i]));
        // exclude
        best=max(best,solve(arr,i+1,ans));
        return best;
    }
};