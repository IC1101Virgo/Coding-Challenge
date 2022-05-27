/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*>mp;
        
        Node* curr=head, *copy;
        
        while(curr!=NULL){
            Node* t=new Node(curr->val);
            mp[curr]=t;
            curr=curr->next;
        }
        
        curr=head;
        while(curr!=NULL){
            copy=mp[curr];
            copy->random=mp[curr->random];
            copy->next=mp[curr->next];
            curr=curr->next;
        }
        
        return mp[head];
    }
};









