class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool leftSide = false) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL && leftSide) return root->val;
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};