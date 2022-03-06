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
    TreeNode* createBinaryTree(vector<vector<int>>& a) {
        unordered_map<int,TreeNode*>nodetree;
        unordered_map<int,bool>ischild;
        
        for(auto &v:a){
            if(nodetree.count(v[0])==0){
                TreeNode* par=new TreeNode(v[0]);
                nodetree[v[0]]=par;
            }
            
             if(nodetree.count(v[1])==0){
                TreeNode* child=new TreeNode(v[1]);
                nodetree[v[1]]=child;
            }
            
            if(v[2]==1) nodetree[v[0]]->left=nodetree[v[1]];
            else nodetree[v[0]]->right=nodetree[v[1]];
            
            ischild[v[1]]=true;
        }
        
        TreeNode *ans=NULL;
        
        for(auto &v:a){
            if(ischild[v[0]]!=true)
            {
                ans=nodetree[v[0]];
                break;
            }
        }
        
        return ans;
    }
};