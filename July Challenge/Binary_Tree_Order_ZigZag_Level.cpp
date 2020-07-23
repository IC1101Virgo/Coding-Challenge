class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if (!root) return res;
        
        queue<TreeNode*> layer;
        layer.push(root);
        int len;
        bool flip = false;
        TreeNode *currNode;
        
        while (layer.size()) {
            len = layer.size();
            vector<int> tmp(len);
            for (int i = 0; i < len; i++) {
                currNode = layer.front();
                tmp[i] = currNode->val;
                if (currNode->left) layer.push(currNode->left);
                if (currNode->right) layer.push(currNode->right);
                layer.pop();
            }
            if (flip) reverse(begin(tmp), end(tmp));
            flip = !flip;
            res.push_back(tmp);
        }
        return res;
    }
};