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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        
        if(!root)
            return v;
        
        stack<TreeNode*> s;
        
        while(1){
            while(root){
                s.push(root);
                root=root->left;
                
            }
            
            if(s.empty())
                break;
            
            root=s.top();
            
            v.push_back(root->val);
            s.pop();
            
            root=root->right;
        }
        
        return v;
    }
};