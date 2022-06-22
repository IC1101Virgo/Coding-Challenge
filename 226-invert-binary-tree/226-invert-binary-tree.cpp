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
    
    TreeNode* invertTree(TreeNode* A) {
        if(!A)
            return NULL;
        
        
       TreeNode *l=invertTree(A->right);
        TreeNode *r=invertTree(A->left);
        
        A->left=l;
        A->right=r;
        
        return A;
    }
};