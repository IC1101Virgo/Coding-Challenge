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
    void helper(TreeNode *root, int &sum, int val){
        if(!root)
            return;
        
        val=val*10+root->val;
        
        if(!root->left && !root->right)
            sum+=val;
        
        helper(root->left,sum,val);
         helper(root->right,sum,val);
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        
        int sum=0,val=0;
        
        helper(root,sum,val);
        
        return sum;
    }
};