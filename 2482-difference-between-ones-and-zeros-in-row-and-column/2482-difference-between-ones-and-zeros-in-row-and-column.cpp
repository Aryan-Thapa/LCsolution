class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) 
    {
        int row=grid.size();
        int col=grid[0].size();
        vector<int>onerow(row,0);
        vector<int>zerosrow(row,0);
        vector<int>onecol(col,0);
        vector<int>zeroscol(col,0);
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                {
                    onerow[i]++;
                    onecol[j]++;
                }
                else
                {
                    zerosrow[i]++;
                    zeroscol[j]++;
                }
            }
        }
        vector<vector<int>> diff(row, vector<int>(col, 0));;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                diff[i][j]=onerow[i] + onecol[j] - zerosrow[i] - zeroscol[j];
            }
        }
        return diff;
    }

};