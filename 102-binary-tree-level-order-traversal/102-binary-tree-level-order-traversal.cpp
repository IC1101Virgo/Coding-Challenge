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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> v;
        
        if(!root)
            return ans;
        
        queue<TreeNode *>q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int s=q.size();
           
            v.clear();
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                 q.pop();
                
                v.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                 if(curr->right) q.push(curr->right);
            }
            
            ans.push_back(v);
        }
        
        return ans;
    }
};