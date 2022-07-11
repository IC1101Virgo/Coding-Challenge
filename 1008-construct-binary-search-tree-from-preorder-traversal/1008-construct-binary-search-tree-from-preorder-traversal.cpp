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
    TreeNode *helper(TreeNode *&root, int ele){
        if(root==NULL)
            return root=new TreeNode(ele);
        
        if(root->val>ele)
            return helper(root->left,ele);
        
        else return helper(root->right,ele);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& pr) {
        TreeNode *root=NULL;
        
        for(auto x:pr){
            helper(root,x);
        }
        
        return root;
    }
};