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
     vector<TreeNode*> res;
    unordered_set<int> s;
    
    void helper(TreeNode* &root){
        
        if(root!=NULL){
        helper(root->left);
        helper(root->right);
        
        if(s.find(root->val)!=s.end()){
            if(root->left) res.push_back(root->left);
            if(root->right) res.push_back(root->right);
            
            root=NULL;
            delete root;
        }
        }
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& t) {
            if(!root)
                return res;
        
        for(auto x:t){
            s.insert(x);
        }
        
        helper(root);
        
        if(root)
            res.push_back(root);
        
        return res;
    }
};