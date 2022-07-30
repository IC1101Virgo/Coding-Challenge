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
    TreeNode* helper(vector<int> &postorder, int &idx, unordered_map<int,int> &mp, int start, int end){
        if(start<=end){
            TreeNode *root=new TreeNode(postorder[idx--]);
            
            root->right=helper(postorder,idx,mp,mp[root->val]+1,end);
            root->left=helper(postorder,idx,mp,start,mp[root->val]-1);
            
            return root;
        }
        
        else return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        
        int n=inorder.size();
        
        for(int i=0;i<n;i++){
            m[inorder[i]]=i;
        }
        
        int idx=n-1;
        
        return helper(postorder,idx,m,0,n-1);
    }
};