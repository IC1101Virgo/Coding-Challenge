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
    TreeNode* helper(vector<int> &pre, int &preidx,unordered_map<int,int>&m, int start, int end){
    if(start>end) return NULL;
    
    TreeNode *root= new TreeNode(pre[preidx++]);
    
    if(start==end) return root;
    
    root->left=helper(pre,preidx,m,start,m[root->val]-1);
    root->right=helper(pre,preidx,m,m[root->val]+1,end);
    
    return root;
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int>m;
    
    for(int i=0;i<in.size();i++)
    m[in[i]]=i;
    
    int n=0;
    
    return helper(pre,n,m,0,in.size()-1);
    }
};