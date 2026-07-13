class Solution {
public:
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr && subRoot == nullptr)
            return true;

        if(root == nullptr || subRoot == nullptr)
            return false;

        if(root->val != subRoot->val)
            return false;

        return check(root->left, subRoot->left) &&
               check(root->right, subRoot->right);
    }

    bool dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr)
            return false;

        if(root->val == subRoot->val && check(root, subRoot))
            return true;

        return dfs(root->left, subRoot) ||
               dfs(root->right, subRoot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return dfs(root, subRoot);
    }
};