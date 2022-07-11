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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        vector<int>v;
        
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        if(!root)
            return res;
        
        while(!q.empty()){
            int n=q.size();
            v.clear();
            
            while(n--){
                TreeNode* temp=q.front();
                q.pop();
                
                
                v.push_back(temp->val);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            level++;
            
            if(level%2==0)
                reverse(v.begin(),v.end());
            
            res.push_back(v);
        }
        
        return res;
    }
};