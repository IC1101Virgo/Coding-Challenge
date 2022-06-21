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
    void helper(TreeNode*root, vector<int> &v){
        if(!root)
            return;
        
        helper(root->left,v);
        v.push_back(root->val);
        helper(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return 1;
        vector<int>v;
        helper(root,v);
        
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])
                return false;
        }
        
        return true;
        
    }
};