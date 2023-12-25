class Solution {
public:
int numdecodehelp(string &s,int pos)
{
    if(pos==s.size())return 1;
    if(s[pos]=='0')return 0;
    if(pos==s.size()-1)return 1;
    string b=s.substr(pos,2);
    int opt1=numdecodehelp(s,pos+1);
    int opt2;
    if(stoi(b)<=26 && stoi(b)>0)
    {
        opt2=numdecodehelp(s,pos+2);
    }
    return opt1+opt2;
}
int memsolve(string &s,int pos,vector<int>&dp)
{
    if(pos==s.size())return 1;
    if(s[pos]=='0')return 0;
    if(pos==s.size()-1)return 1;
    if(dp[pos]!=-1)return dp[pos];
    string b=s.substr(pos,2);
    int opt1=memsolve(s,pos+1,dp);
    int opt2;
    if(stoi(b)<=26 && stoi(b)>0)
    {
        opt2=memsolve(s,pos+2,dp);
    }
    dp[pos]=opt1+opt2;
    return dp[pos];
}
int tabulation(string s)
{
    int n=s.size();
    vector<int>dp(s.size()+1,-1);
    dp[0]=1;
    if(s[0]=='0')
    {
        dp[1]=0;
    }
    else
    {
        dp[1]=1;
    }
    for(int i=2;i<=n;i++)
    {
        string b=s.substr(i-2,2);
        int opt1=0;
        if(s[i-1]!='0')opt1=dp[i-1];;
        int opt2=0;
        if(stoi(b)<=26 && stoi(b)>0 &&s[i-2]!='0')
        {
            opt2=dp[i-2];
        }
        dp[i]=opt1+opt2;
    }
    return dp[n];
}
    int numDecodings(string s) 
    {
        // int ans=numdecodehelp(s,0);
        // return ans; 
        // int n=s.size();
        // vector<int>dp(n+1,-1);
        // return memsolve(s,0,dp);
        return tabulation(s);
    }
};