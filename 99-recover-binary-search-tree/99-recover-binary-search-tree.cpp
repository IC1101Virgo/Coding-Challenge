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
    TreeNode *prev=NULL, *node1=NULL, *node2=NULL;
    
    void helper(TreeNode *root){
        if(!root)
            return;
        
        helper(root->left);
        
       if(prev!=NULL && root->val<prev->val){
           if(node1==NULL)
               node1=prev;
           if(node1!=NULL)
               node2=root;
       }
        
        prev=root;
        
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(!root)
            return;
        
        helper(root);
        
        swap(node1->val,node2->val);
    }
};