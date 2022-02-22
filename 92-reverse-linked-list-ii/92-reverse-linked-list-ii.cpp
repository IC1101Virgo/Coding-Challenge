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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return head;
        
        ListNode *temp, *curr=head, *prev=NULL;
        
        while(m>1){
            prev=curr;
            curr=curr->next;
            m--;
            n--;
        }
        
        ListNode *con=prev, *tail=curr;
        
        while(n>0){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            n--;
        }
        
        if(con!=NULL){
            con->next=prev;
        }
        
        else 
            head=prev;
        
        tail->next=curr;
        return head;
        
    }
};