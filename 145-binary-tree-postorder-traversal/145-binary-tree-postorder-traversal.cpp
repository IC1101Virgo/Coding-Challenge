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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        
        if(!root)
            return v;
        
        stack<TreeNode*>s;
        
        s.push(root);
        
        while(!s.empty()){
            TreeNode *temp=s.top();
            
            if(temp->left!=NULL){
                s.push(temp->left);
                temp->left=NULL;
                continue;
            }
            
            if(temp->right!=NULL){
                s.push(temp->right);
                temp->right=NULL;
                continue;
            }
            
            v.push_back(temp->val);
            s.pop();
        }
        
        return v;
    }
};