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
    void helper(TreeNode* root, int t, int sum, vector<int> v){
        if(!root)
            return;
        
        sum+=root->val;
        v.push_back(root->val);
        
        if(!root->right && !root->left && sum==t){
            res.push_back(v);
            v.clear();
        }
        
        helper(root->left,t,sum,v);
         helper(root->right,t,sum,v);
        
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
      vector<int>v;
        
        helper(root,t,0,v);
        
        return res;
        
    }
};