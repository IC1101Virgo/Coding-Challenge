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
    unordered_map<int,TreeNode*> um;
    
    TreeNode* helper(int val){
        TreeNode *node=NULL;
        
        if(um.find(val)==um.end()){
            node=new TreeNode(val);
            um[val]=node;
        }
        
        else{
            node=um[val];
        }
        
        return node;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_set<int> m;
        
        
        for(auto& des : descriptions){
            int p=des[0], c=des[1];
            bool l=des[2];
            
             TreeNode *x=helper(p);
            
            if(l){
                x->left=helper(c);
            }
            
            else{
                x->right=helper(c);
            }
            m.insert(c);
            
        }
        
        for(auto& [node, ptr] : um) {
            if(m.find(node) == m.end()) return ptr;
        }
        return NULL;
    }
};