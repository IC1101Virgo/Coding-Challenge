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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return 1;
        
        ListNode *fast=head, *slow=head;
        
        ListNode* temp=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            temp=slow->next;
        }
        
        
        temp=head;
        
        ListNode *prev=NULL, *next=NULL;
        
        while(slow){
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        
        while(prev){
            if(temp->val != prev->val)
                return 0;
            temp=temp->next;
            prev=prev->next;
        }
        return 1;
    }
};