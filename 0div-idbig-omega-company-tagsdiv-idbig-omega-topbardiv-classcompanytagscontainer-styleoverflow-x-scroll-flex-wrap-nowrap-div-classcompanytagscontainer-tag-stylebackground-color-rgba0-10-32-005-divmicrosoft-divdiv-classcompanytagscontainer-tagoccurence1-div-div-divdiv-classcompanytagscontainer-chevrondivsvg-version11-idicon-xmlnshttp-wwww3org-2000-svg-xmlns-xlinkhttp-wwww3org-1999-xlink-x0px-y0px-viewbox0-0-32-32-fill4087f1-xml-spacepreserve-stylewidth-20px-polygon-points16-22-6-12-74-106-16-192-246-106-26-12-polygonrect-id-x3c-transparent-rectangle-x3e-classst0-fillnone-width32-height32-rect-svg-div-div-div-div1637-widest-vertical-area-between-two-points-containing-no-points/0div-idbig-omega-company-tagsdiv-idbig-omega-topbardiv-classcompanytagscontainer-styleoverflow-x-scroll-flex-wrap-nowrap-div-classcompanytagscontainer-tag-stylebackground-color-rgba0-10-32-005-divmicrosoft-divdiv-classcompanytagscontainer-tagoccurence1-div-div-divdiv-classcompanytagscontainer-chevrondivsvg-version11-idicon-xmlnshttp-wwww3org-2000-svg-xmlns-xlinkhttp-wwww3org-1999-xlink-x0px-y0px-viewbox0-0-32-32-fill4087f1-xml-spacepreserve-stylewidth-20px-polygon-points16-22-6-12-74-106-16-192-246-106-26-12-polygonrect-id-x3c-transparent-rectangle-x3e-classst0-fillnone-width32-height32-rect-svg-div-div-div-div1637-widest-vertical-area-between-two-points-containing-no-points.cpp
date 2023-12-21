class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) 
    {
         vector<int>xaxis;
         for(auto i:points)
         {
             xaxis.push_back(i[0]);
         }
         sort(xaxis.begin(),xaxis.end());
         int maxi=INT_MIN;
         int prev=xaxis[0];
         for(int i=1;i<xaxis.size();i++)
         {
            int diff=xaxis[i]-prev;
            maxi=max(diff,maxi);
            prev=xaxis[i];
         }
         return maxi;  
    }
};