class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int count=1;
        int ans;
        int n=arr.size();
        int perc=n/4;
        //int first=arr[0];
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]==arr[i-1])
            {
                count++;
                if(count>perc)
                {
                    ans=arr[i];
                    break;
                }
            }
            else
            {
                count=1;
            }
        }
        return ans;    
    }
};