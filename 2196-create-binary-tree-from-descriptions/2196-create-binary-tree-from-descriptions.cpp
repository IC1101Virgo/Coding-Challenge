class Solution {
private: 
		// Map to store node value and its pointer
	    unordered_map<int, TreeNode*> nodeMap;
private: 
	// Helper function to getNode by value
	TreeNode* getNode(int val) {
        TreeNode* node = NULL;
		// If node is not present in map, 
		// Then create a new node, and store it in map
        if(nodeMap.find(val) == nodeMap.end()) {
            node = new TreeNode(val);
            nodeMap[val] = node;
        }
		// If node is already present in map then return it
        else {
            node = nodeMap[val];
        }
        return node;
    }
public:
       
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_set<int> isChild; // used to track if a node is child of some other node
        for(auto& description : descriptions) {
            int val = description[0], child = description[1];
            bool left = (description[2]);
            
			// Get node and then connect to left or right child accordingly
            TreeNode* node = getNode(val);
            if(left) {
                node->left = getNode(child);
            }
            else {
                node->right = getNode(child);   
            }
            isChild.insert(child);
        }
        
		// Iterate over map, and get root node
        for(auto& [node, ptr] : nodeMap) {
            if(isChild.find(node) == isChild.end()) return ptr;
        }
        return NULL;
    }
};