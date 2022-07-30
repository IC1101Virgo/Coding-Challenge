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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        size_t ans=0;
        
        queue<pair<TreeNode*,size_t>>q;
        
        q.push({root,1});
        
        while(!q.empty()){
            ans=max(ans,q.back().second-q.front().second);
            int size=q.size();
            
            while(size--){
                auto [node,ind]=q.front();
                q.pop();
                
                if(node->left) q.push({node->left,2*ind});
                if(node->right) q.push({node->right,2*ind+1});
            }
        }
        
        return ans+1;
    }
};