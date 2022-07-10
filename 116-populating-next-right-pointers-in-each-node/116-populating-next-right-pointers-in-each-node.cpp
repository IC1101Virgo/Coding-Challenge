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
       queue<Node*>q;
        if(!root)return NULL;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            Node* prev = NULL;
            for(int i=0; i< sz; i++){
                Node* cur = q.front();
                //if(i == sz-1)cur->next = NULL;
                if(i>0){
                    prev->next =cur;
                }
                q.pop();
                
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
                
                prev = cur;
            }
        }
        return root;
    }
};