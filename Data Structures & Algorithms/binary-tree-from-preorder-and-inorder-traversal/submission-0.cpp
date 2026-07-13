class Solution {
public:

    TreeNode* make(vector<int>& preorder,
                   int prestart,
                   int preend,
                   vector<int>& inorder,
                   int instart,
                   int inend,
                   map<int,int>& mpp)
    {
        if(prestart > preend || instart > inend)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[prestart]);

        int inroot = mpp[root->val];
        int numsLeft = inroot - instart;

        root->left = make(preorder,
                          prestart + 1,
                          prestart + numsLeft,
                          inorder,
                          instart,
                          inroot - 1,
                          mpp);

        root->right = make(preorder,
                           prestart + numsLeft + 1,
                           preend,
                           inorder,
                           inroot + 1,
                           inend,
                           mpp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int n = preorder.size();
        int m = inorder.size();

        map<int,int> mpp;

        for(int i = 0; i < m; i++)
            mpp[inorder[i]] = i;

        return make(preorder, 0, n-1,
                    inorder, 0, m-1,
                    mpp);
    }
};