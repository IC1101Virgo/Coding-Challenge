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
   
 void helper(TreeNode *A, int val,int &sum){
     if(!A)
     return;
     
     val=(val*10+A->val);
     if(!A->left && !A->right)
     sum=(sum+val);
     
     helper(A->left,val,sum);
     helper(A->right,val,sum);
     
 }
    int sumNumbers(TreeNode* A) {
        if(!A)
    return 0;
    
    int sum=0,val=0;
    
    helper(A,val,sum);
    
    return sum;
    }
};