class Solution {
public:
    int fun(TreeNode* root, int& maxi)
    {
        if(root == nullptr)
            return 0;

        int l = max(0, fun(root->left, maxi));
        int r = max(0, fun(root->right, maxi));

        maxi = max(maxi, root->val + l + r);

        return root->val + max(l, r);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        fun(root, maxi);

        return maxi;
    }
};