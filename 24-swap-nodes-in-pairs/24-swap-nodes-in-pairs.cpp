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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        ListNode *curr=head, *next=NULL, *prev=NULL;
        
        int count=0;
        
        while(count<2 && curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
            count++;
        }
        
        if(next!=NULL)
        head->next= swapPairs(next);
        
        return prev;
        
    }
};