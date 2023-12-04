class Solution {
public:
void merge(vector<int>& nums,int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int* left=new int[len1];
    int* right=new int[len2];
    int k=s;
    //copying the values to the left and right array
    for(int i=0;i<len1;i++)
    {
        left[i]=nums[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<len2;i++)
    {
        right[i]=nums[k];
        k++;
    }
    //applying the merge 2 pointer logic
    int leftindex=0;
    int rightindex=0;
    int mainindex=s;
    while(leftindex<len1 && rightindex<len2)
    {
        if(left[leftindex]<right[rightindex])
        {
            nums[mainindex++]=left[leftindex++];
        }
        else
        {
            nums[mainindex++]=right[rightindex++];
        }
    }
    while(leftindex<len1)
    {
        nums[mainindex++]=left[leftindex++];
    }
    while(rightindex<len2)
    {
        nums[mainindex++]=right[rightindex++];
    }
}
void mergesort(vector<int>& nums,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    //merge left
    int mid=s+(e-s)/2;
    mergesort(nums,s,mid);
    //merge right
    mergesort(nums,mid+1,e);
    merge(nums,s,e);
}
    vector<int> sortArray(vector<int>& nums) 
    {
        int s=0;
        int e=nums.size()-1;
        mergesort(nums,s,e);
        return nums;    
    }
};