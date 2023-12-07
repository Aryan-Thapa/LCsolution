class Solution {
public:
void solve(string &digits,vector<string>&ans,string output,int i,vector<string>&mapping)
{
    //base case
    if(i>=digits.length())
    {
        ans.push_back(output);
        return;
    }
    //store the current digit
    int digit=digits[i]-'0';
    string value=mapping[digit];
    for(int j=0;j<value.length();j++)
    {
        char ch=value[j];
        //store curr character (1 case solve karo)
        output.push_back(ch);
        //rec call
        solve(digits,ans,output,i+1,mapping);
        //backtrack
        output.pop_back();
    }
}
    vector<string> letterCombinations(string digits) 
    {
        vector<string>ans;
        if(digits.length()==0)
        {
            return ans;
        }
        string output="";
        int i=0;
        vector<string>mapping(10);
        mapping[2]="abc";
        mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
        solve(digits,ans,output,i,mapping);
        return ans;

    }
};