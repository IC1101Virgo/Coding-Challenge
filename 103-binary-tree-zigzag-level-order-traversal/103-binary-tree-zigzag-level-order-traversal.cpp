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
        vector<vector<int>> v;
        
        queue<TreeNode *> q;
        
        if(root==NULL)
            return v;
        
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            vector<int> temp;
            
            while(n--){
                TreeNode *node=q.front();
                q.pop();
                
                temp.push_back(node->val);
                
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                

            }
            level++;
            
            if(level%2==0)
            {
                reverse(temp.begin(),temp.end());
                
            }
            
            v.push_back(temp);
        }
        
        return v;
    }
};