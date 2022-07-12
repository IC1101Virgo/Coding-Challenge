/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
         if(!root)
       return root;
       
       if(root==n1||root==n2)
       return root;
       
       TreeNode *left=lowestCommonAncestor(root->left,n1,n2);
       TreeNode *right=lowestCommonAncestor(root->right,n1,n2);
       
       if(left!=NULL and right!=NULL)
       return root;
       
       return left!=NULL?left:right;
        
    }
};