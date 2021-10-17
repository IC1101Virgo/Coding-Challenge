class Solution {
public:
    int cnt=0;
    void helper(TreeNode *root, int targetSum, vector<int> &help){
        if(!root) return;
        
        help.push_back(root->val);
        int sum=0;
        for(int i=help.size()-1;i>=0;i--){
    
            sum+=help[i];
            if(sum==targetSum)
                cnt++;
        }
        
        helper(root->left,targetSum,help);
        helper(root->right,targetSum,help);
        help.pop_back();
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> help;
        helper(root,targetSum,help);
        
        return cnt;
    }
};
