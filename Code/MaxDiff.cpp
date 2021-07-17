class Solution {
public:
    int helper(TreeNode *root, int mx, int mn){
        if(!root) return NULL;
        
        mx=max(mx,root->val);
        mn=min(mn,root->val);
        
        return max({helper(root->left,mx,mn), helper(root->right,mx, mn), mx - mn});
    }
    int maxAncestorDiff(TreeNode* root) {
        int mx,mn;
        return helper(root,INT_MIN,INT_MAX);
    }
};
