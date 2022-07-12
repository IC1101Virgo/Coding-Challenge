/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if(!root)
            return NULL;
        
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            Node* prev=NULL;
            
            for(int i=0;i<n;i++){
                Node* curr=q.front();
                
                if(i>0)
                    prev->next=curr;
                
                q.pop();
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
                
                prev=curr;
            }
        }
        
        return root;
    }
};