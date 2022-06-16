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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1=new ListNode (0);
        ListNode *l2=new ListNode (0);
        ListNode *ptr1=l1, *ptr2=l2, *curr=head;
        
        while(curr!=NULL){
            if(curr->val<x){
                ptr1->next=curr;
                ptr1=ptr1->next;
            }
            
            else if(curr->val>=x){
                ptr2->next=curr;
                ptr2=ptr2->next;
            }
            curr=curr->next;
        }
        
         
        ptr1->next=l2->next;
       ptr2->next=NULL;
        
       
        
        return l1->next ;
    }
};