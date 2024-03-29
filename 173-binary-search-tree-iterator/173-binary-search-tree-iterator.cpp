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
class BSTIterator {
public:
    stack<TreeNode*>s;
    void helper(TreeNode *root){
        while(root){
            s.push(root);
            root=root->left;
        }
        return;
    }
    BSTIterator(TreeNode* root) {
        helper(root);
    }
    
    int next() {
        TreeNode *x= s.top();
        s.pop();
        helper(x->right);
        return x->val;
    }
    
    bool hasNext() {
        
        if(!s.empty())
            return 1;
        
        else return 0;
        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */