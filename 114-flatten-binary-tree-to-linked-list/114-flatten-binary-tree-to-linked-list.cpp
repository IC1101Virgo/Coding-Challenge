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
    void flatten(TreeNode* A) {
       if(!A)
    return ;
    
   stack<TreeNode*> s;
   s.push(A);
   
   while(!s.empty()){
       
       TreeNode *x=s.top();
       s.pop();
       
       if(x->right){
           s.push(x->right);
           
       }
       
       if(x->left){
           s.push(x->left);
          
       }
       
       if(!s.empty())
       x->right=s.top();
        x->left=NULL;
       
       
   }
   
   return ;
    }
};