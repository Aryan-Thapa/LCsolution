class Solution {
public:
int numSpecial(vector<vector<int>>& mat) {
    vector<int> rows(mat.size());
    vector<int> cols(mat[0].size());
    for (int i = 0; i < rows.size(); i++)
    {
        for (int j = 0; j < cols.size(); j++) 
        {
            if (mat[i][j]==1)
            {
                rows[i]++; 
                cols[j]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < rows.size(); ++i)
    {
        for (int j = 0; j < cols.size(); ++j)
        {
            if (mat[i][j]==1 && rows[i] == 1 && cols[j] == 1)
            {
                ans++;
            }
        }
    }
    return ans;
}
};