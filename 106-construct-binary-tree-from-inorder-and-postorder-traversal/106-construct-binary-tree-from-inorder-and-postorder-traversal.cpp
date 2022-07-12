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
    TreeNode* helper(vector<int>& postorder, int &postidx, unordered_map<int,int> &m, int start, int end){
        int n=postorder.size();
        
        if(start<=end){
            TreeNode *root=new TreeNode(postorder[postidx--]);
            
            root->right=helper(postorder,postidx,m,m[root->val]+1,end);
            root->left=helper(postorder,postidx,m,start,m[root->val]-1);
            
            return root;
        }
        
        else return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        int n=postorder.size()-1;
        
        return helper(postorder,n,m,0,n);
    }
};