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
    int ans=0;
    
    int solve(TreeNode* root){
        if(!root)
            return 0;
        
        int l=solve(root->left);
        int r=solve(root->right);
        
        int temp=l+r;
        
        ans=max(temp,ans);
        
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        solve(root);
        
        return ans;
    }
};