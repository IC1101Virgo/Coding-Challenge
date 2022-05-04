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
    vector<vector<int>> res;
    
    void helper(TreeNode *root, int sum, vector<int> v, int t){
        if(!root)
            return;
        
        sum+=root->val;
        v.push_back(root->val);
        
        if(!root->left && !root->right && sum==t){
            res.push_back(v);
            v.clear();
        }
        
        helper(root->left,sum,v,t);
         helper(root->right,sum,v,t);
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        if(!root)
            return res;
        
        vector<int> v;
        
        int sum=0;
        helper(root,sum,v,t);
        
        return res;
        
    }
};