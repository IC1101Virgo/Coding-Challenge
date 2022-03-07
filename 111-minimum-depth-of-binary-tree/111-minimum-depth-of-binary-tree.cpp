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
    int minDepth(TreeNode* A) {
        if(!A)
    return NULL;
    
    if(A->left==NULL||A->right==NULL)
    return 1+max(minDepth(A->left),minDepth(A->right));
    
    else return 1+min(minDepth(A->left),minDepth(A->right));
    }
};