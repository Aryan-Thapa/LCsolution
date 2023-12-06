class Solution {
public:
void storeSolution(vector<vector<char>> &m, int n, vector<vector<string> > &ans) 
{
    vector<string> temp;
    for(int i=0; i<n; i++) 
    {
        string output = "";
        for(int j=0; j<n ;j++) 
        {
            output.push_back(m[i][j]);
        }
        temp.push_back(output);
    }
    ans.push_back(temp);
}
bool issafe(int row,int col,vector<vector<char>>&m,int n)
{
    int i=row;
    int j=col;
    //check row
    while(j>=0)
    {
        if(m[i][j]=='Q')
        {
            return false;
        }
        j--;
    }
    i=row;
    j=col;
    //check lower diagnol
    while(i<n && j>=0)
    {
        if(m[i][j]=='Q')
        {
            return false;
        }
        i++;
        j--;
    }
    i=row;
    j=col;
    //check upper diagnol
    while(i>=0 && j>=0)
    {
        if(m[i][j]=='Q')
        {
            return false;
        }
        i--;
        j--;
    }
    return true;

}
void solve(vector<vector<char>>&m,int n,int col,vector<vector<string>>&ans)
{
    //base case
    if(col>=n)
    {
        storeSolution(m,n,ans);
        return;
    }
    for(int row=0;row<n;row++)
    {
        if(issafe(row,col,m,n))
        {
            m[row][col]='Q';
            //rec call
            solve(m,n,col+1,ans);
            //backtrack
            m[row][col]='.';
        }
    }
}
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        vector<vector<char>>m(n,vector<char>(n,'.'));
        int col=0;
        solve(m,n,col,ans);
        return ans;   
    }
};