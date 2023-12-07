class Solution {
public:
    string largestOddNumber(string num) 
    {
        int i = num.size() - 1;
        while (i >= 0 && (num[i] - '0') % 2 == 0)
        {
            i--;
        }
        return num.substr(0, i + 1);
    }
};