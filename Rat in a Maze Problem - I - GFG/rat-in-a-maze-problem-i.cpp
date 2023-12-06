//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool issafe(int i,int j,vector<vector<int>> &m,int n,vector<vector<bool>>&visited)
    {
        if((i>=0 && i<n) && (j>=0 && j<n) && visited[i][j]==false && m[i][j]==1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void findpathhelp(vector<vector<int>> &m, int n,int i,int j,vector<string>&path,vector<vector<bool>>&visited,string output)
    {
        //base case
        if(i==n-1 && j==n-1)
        {
            path.push_back(output);
            return;
        }
        //check if the index is safe or not
        //down
        if(issafe(i+1,j,m,n,visited))
        {
            //mark the index as visited 
            visited[i+1][j]=true;
            //rec call
            findpathhelp(m,n,i+1,j,path,visited,output+'D');
            //backtrack
            visited[i+1][j]=false;
        }
        //left
        if(issafe(i,j-1,m,n,visited))
        {
            //mark the index as visited 
            visited[i][j-1]=true;
            //rec call
            findpathhelp(m,n,i,j-1,path,visited,output+'L');
            //backtrack
            visited[i][j-1]=false;
        }
        //right
        if(issafe(i,j+1,m,n,visited))
        {
            //mark the index as visited 
            visited[i][j+1]=true;
            //rec call
            findpathhelp(m,n,i,j+1,path,visited,output+'R');
            //backtrack
            visited[i][j+1]=false;
        }
        //up
        if(issafe(i-1,j,m,n,visited))
        {
            //mark the index as visited 
            visited[i-1][j]=true;
            //rec call
            findpathhelp(m,n,i-1,j,path,visited,output+'U');
            //backtrack
            visited[i-1][j]=false;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) 
    {
        // Your code goes here
        vector<string>path;
        if(m[0][0]==0)
        {
            return path;
        }
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        visited[0][0]=true;
        int i=0;
        int j=0;
        string output="";
        findpathhelp(m,n,i,j,path,visited,output);
        return path;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends