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
    vector<int> preorderTraversal(TreeNode* root) {
          stack<TreeNode*> s;
        vector<int>v;
        
        if(!root)
            return v;
        
        while(1){
            while(root){
                s.push(root);
                v.push_back(root->val);
                root=root->left;
            }
            
            if(s.empty())
                break;
            
            root=s.top();
            s.pop();
            
            root=root->right;
            
            
        }
        
        return v;
    }
};