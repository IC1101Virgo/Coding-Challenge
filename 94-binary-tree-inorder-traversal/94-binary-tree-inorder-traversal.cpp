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
    vector<int> inorderTraversal(TreeNode* A) {
        stack<TreeNode *> s;
    
   
    
    vector<int> v;
    if(A==NULL) return v;
    
    while(1){
        while(A){
            s.push(A);
            A=A->left;
        }
        
        if(s.empty())
        break;
        
        A=s.top();
        s.pop();
        v.push_back(A->val);
        
        A=A->right;
        
    }
    
    return v;
    }
};