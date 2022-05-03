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
     void helper(TreeNode *A, vector<int>&v){
     if(!A)
     return;

     helper(A->left,v);
     v.push_back(A->val);
     helper(A->right,v);
 }
    bool findTarget(TreeNode* A, int B) {
        vector<int> v;

    helper(A,v);

    unordered_map<int,int>m;

    for(int i=0;i<v.size();i++){
        if(m.find(B-v[i])!=m.end())
        return 1;
        
        m[v[i]]++;
    }
    
    return 0;
    }
};