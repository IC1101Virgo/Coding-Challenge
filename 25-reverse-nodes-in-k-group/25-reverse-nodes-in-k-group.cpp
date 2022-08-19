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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return head;
        
        ListNode *curr=head;
        
        for(int i=0; i<k; i++){
            if(curr==NULL)
                return head;
            
            curr=curr->next;
        }
        
        ListNode *prev=NULL, *next;
        curr=head;
        
        for(int i=0; i<k; i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
       // head=prev;
        
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};