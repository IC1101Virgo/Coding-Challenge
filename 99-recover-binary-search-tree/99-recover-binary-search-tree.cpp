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
    TreeNode *node1=NULL, *node2=NULL, *prev=NULL;
    void inorder(TreeNode *root){
        if(!root)
            return;
        
        inorder(root->left);
        
        if(prev!=NULL && root->val<prev->val){
            if(node1==NULL)
                node1=prev;
            if(node1!=NULL)
                node2=root;
        }
        
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
         if(!root)
            return;
        
        inorder(root);
        
        if(node1 && node2)
            swap(node1->val,node2->val);
    }
};