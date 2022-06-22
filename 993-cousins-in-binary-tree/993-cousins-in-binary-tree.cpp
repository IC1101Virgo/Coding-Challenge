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
    bool isCousins(TreeNode* A, int x, int y) {
        
    
    queue<TreeNode *> q;
    
    q.push(A);
   
    
    while(!q.empty() ){
        int n=q.size();
        bool f1=0, f2=0;
        
        while(n--){
            TreeNode *temp=q.front();
            q.pop();
            
            if(temp->val==x)
                f1=1;
            if(temp->val==y)
                f2=1;
            
            if(temp->left && temp->right){
                if(temp->left->val==x && temp->right->val==y || temp->right->val==x && temp->left->val==y)
                    return false;
            }
            
            
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            
            
        }
        
       
             if(f1 && f2)
            return 1;
    }
    
    return 0;
    
    }
};