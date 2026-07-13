class Solution {
public:

    bool getPath(TreeNode* root, TreeNode* target,
                 vector<TreeNode*>& path)
    {
        if(root == NULL) return false;

        path.push_back(root);

        if(root == target)
            return true;

        if(getPath(root->left, target, path) ||
           getPath(root->right, target, path))
            return true;

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q)
    {
        vector<TreeNode*> path1, path2;

        getPath(root, p, path1);
        getPath(root, q, path2);

        TreeNode* ans = NULL;

        int n = min(path1.size(), path2.size());

        for(int i = 0; i < n; i++)
        {
            if(path1[i] == path2[i])
                ans = path1[i];
            else
                break;
        }

        return ans;
    }
};