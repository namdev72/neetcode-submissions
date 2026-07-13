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
    int dfs(TreeNode* root,int Maxi)
    {
        if(root==NULL) return 0;
        int ans=0;
        if(root->val>=Maxi)
        {
            ans=1;
            Maxi=max(Maxi,root->val);
        }
        ans+=dfs(root->left,Maxi);
        ans+=dfs(root->right,Maxi);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
