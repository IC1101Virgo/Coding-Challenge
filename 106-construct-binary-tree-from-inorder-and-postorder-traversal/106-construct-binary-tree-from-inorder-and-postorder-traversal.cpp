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
    TreeNode *helper(vector<int>&pre,int &preidx,unordered_map<int,int>&m,int start, int end){
        
        
    if(start<=end){
    TreeNode *root= new TreeNode(pre[preidx--]);
    
   
    root->right=helper(pre,preidx,m,m[root->val]+1,end);
    root->left=helper(pre,preidx,m,start,m[root->val]-1);
       
    
    
    return root;
    }
        else return NULL;
           
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pre) {
         unordered_map<int,int>mp;
    
    for(int i=0;i<in.size();i++)
    mp[in[i]]=i;
    
    int n=in.size()-1;
    
    return helper(pre,n,mp,0,in.size()-1);
    }
};