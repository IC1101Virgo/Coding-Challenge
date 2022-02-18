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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        
        vector<int>v;
        
        if(!root)
            return ans;
        
        queue<TreeNode*> q;
        q.push(root);
       
        
        while(!q.empty()){
            int s=q.size();
            v.clear();
            
            for(int i=0;i<s;i++){
                TreeNode* x=q.front();
                q.pop();
                
                v.push_back(x->val);
               
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
            }
            
            ans.push_back(v);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};