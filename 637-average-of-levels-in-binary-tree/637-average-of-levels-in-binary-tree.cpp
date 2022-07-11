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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        if(!root) return ans;
        
        while(!q.empty()){
            int n=q.size();
            double avgg=0;
            int ns=n;
            while(n--){
                TreeNode *temp=q.front();
                q.pop();
                
                avgg+=temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                
            }
            
            ans.push_back(avgg/ns);
        }
        
        return ans;
    }
};