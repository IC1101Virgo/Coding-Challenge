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
    int cnt=0;
    void dfs(TreeNode* root, int t, vector<int> &help){
        if(!root)
            return;
        
        help.push_back(root->val);
        int sum=0;
        
        for(int i=help.size()-1;i>=0;i--){
            sum+=help[i];
            if(sum==t)
                cnt++;
        }
        
        dfs(root->left,t,help);
         dfs(root->right,t,help);
        help.pop_back();
    }
    int pathSum(TreeNode* root, int t) {
        vector<int> help;
        dfs(root,t,help);
        return cnt;
        
    }
};