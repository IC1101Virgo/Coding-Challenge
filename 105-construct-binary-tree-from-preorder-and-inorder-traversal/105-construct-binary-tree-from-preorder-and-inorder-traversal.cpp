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
    TreeNode *helper(vector<int>&pre, int &ind, unordered_map<int,int> &mp, int lo, int hi){
        if(lo<=hi){
            TreeNode *root=new TreeNode(pre[ind++]);
            root->left=helper(pre,ind,mp,lo,mp[root->val]-1);
            root->right=helper(pre,ind,mp,mp[root->val]+1,hi);
            return root;
        }
        
        return NULL;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<in.size();i++)
            mp[in[i]]=i;
        
        int ind=0;
        return helper(pre,ind,mp,0,in.size()-1);
    }
};