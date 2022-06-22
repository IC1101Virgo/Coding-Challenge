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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        
        if(!root)
            return v;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
           
            int s=q.size();
            
            for(int i=0;i<s;i++){
                 TreeNode *curr=q.front();
            q.pop();
                
                if(i==s-1)
                    v.push_back(curr->val);
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        
        return v;
    }
};