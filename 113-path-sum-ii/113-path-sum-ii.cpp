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
    void helper(TreeNode *root, int t, int sum, vector<int>v){
        if(!root)
            return;
        
         v.push_back(root->val);
        sum+=root->val;
       
        
        if(!root->left && !root->right && sum==t)
        {
            res.push_back(v);
           // v.clear();
           // sum=0;
        }
        
        helper(root->left,t,sum,v);
        helper(root->right,t,sum,v);
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> v;
        
        if(!root)
            return res;
        
        int sum=0;
        
        helper(root,t,sum,v);
        
        return res;
    }
};