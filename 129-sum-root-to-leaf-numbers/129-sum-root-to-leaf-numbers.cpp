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
    void helper(TreeNode *A, int val,int &ans){
     if(!A)
     return;
     
     val=(val*10+A->val);
     
     if(A->left==A->right)
     ans=(ans+val);
     
     helper(A->left,val,ans);
      helper(A->right,val,ans);
 }
    int sumNumbers(TreeNode* A) {
        if(!A) return 0;
        int ans=0;
    helper(A,0,ans);
    
    return ans;
    }
};