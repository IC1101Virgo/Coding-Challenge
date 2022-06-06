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
    int maxs=INT_MIN;
    
    int helper(TreeNode* root){
        if(!root)
            return 0;
        
        int l=max(helper(root->left),0);
        int r=max(helper(root->right),0);
        
        int price=root->val+l+r;
        
        maxs=max(maxs,price);
        
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxs;
        
    }
};