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
            TreeNode *root=new TreeNode(postorder[postidx++]);
            
            
            root->left=helper(postorder,postidx,m,start,m[root->val]-1);
            root->right=helper(postorder,postidx,m,m[root->val]+1,end);
            
            return root;
        }
        
        else return NULL;
    }
    TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder) {
          unordered_map<int,int> m;
        
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        
        int n=postorder.size()-1;
        int x=0;
        return helper(postorder,x,m,0,n);
    }
};