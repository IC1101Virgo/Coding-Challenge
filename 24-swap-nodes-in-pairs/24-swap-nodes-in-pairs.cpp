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
        ListNode *curr=head;
        
        for(int i=0;i<2;i++){
            if(!curr)
                return head;
            curr=curr->next;
        }
        
        ListNode *prev=NULL,*next=NULL,*temp=head;
        
        for(int i=0;i<2;i++){
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        
        head->next=swapPairs(temp);
        
        return prev;
        
    }
};