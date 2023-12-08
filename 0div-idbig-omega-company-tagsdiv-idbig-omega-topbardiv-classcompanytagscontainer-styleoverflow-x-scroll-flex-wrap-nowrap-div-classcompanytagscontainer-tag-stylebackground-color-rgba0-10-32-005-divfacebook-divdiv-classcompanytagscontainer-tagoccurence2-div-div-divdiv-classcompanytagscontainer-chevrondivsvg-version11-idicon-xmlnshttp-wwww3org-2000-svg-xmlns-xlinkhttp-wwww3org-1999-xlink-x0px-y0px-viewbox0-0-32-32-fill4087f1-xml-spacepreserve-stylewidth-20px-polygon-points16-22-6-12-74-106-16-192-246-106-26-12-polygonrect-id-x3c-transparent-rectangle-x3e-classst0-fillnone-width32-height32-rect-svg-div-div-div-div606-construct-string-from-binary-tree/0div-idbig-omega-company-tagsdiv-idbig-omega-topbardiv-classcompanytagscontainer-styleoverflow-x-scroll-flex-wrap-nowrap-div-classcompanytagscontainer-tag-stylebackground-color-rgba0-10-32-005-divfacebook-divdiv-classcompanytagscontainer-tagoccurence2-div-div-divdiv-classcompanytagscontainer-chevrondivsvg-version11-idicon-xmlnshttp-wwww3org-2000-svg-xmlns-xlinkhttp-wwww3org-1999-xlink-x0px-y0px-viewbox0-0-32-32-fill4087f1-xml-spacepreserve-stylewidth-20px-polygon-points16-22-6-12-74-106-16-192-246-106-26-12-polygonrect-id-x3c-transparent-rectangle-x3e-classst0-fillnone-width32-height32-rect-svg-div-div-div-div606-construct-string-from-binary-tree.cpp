/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void preordertraversal(TreeNode* root,string &ans)
{
    //bc
    if(root==NULL)
    {
        return;
    }
    //NLR
    if(root->val>=0)
    {
        ans+=to_string(root->val);
    }
    else if(root->val < 0)
    {
        ans.push_back('-');
        ans += to_string(abs(root->val));
    }
    
    if(root->left)
    {
            ans.push_back('(');
            preordertraversal(root->left,ans);
            ans.push_back(')');
    }
    if(root->right)
    {
        if(!root->left) 
        {
            ans.push_back('(');
            ans.push_back(')');
        }
        ans.push_back('(');
        preordertraversal(root->right,ans);
        ans.push_back(')');
    }

    
}
    string tree2str(TreeNode* root) 
    {
        string ans="";
        preordertraversal(root,ans);
        return ans;
    }
};