/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head)
            return;
        
        stack<ListNode*> s;
        
        int l=0;
        
        ListNode *curr=head, *temp=head;
        
        while(curr){
             s.push(curr);
            l++;
            curr=curr->next;
        }
        
        curr=head;
        
        for(int i=0;i<l/2;i++){
            ListNode *ele=s.top();
            s.pop();
            ele->next=curr->next;
            curr->next=ele;
            curr=curr->next->next;
        }
        
        curr->next=NULL;
        
    }
};