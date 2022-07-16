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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k==0)
            return head;
        
        int l=1;
        
        ListNode *temp=head;
        
        while(temp->next){
            l++;
            temp=temp->next;
        }
        temp->next=head;
        
        //temp=head;
        
        
            k=k%l;
        
        k=l-k;
        
        while(k--){
            temp=temp->next;
        }
        
        ListNode *x=temp->next;
        temp->next=NULL;
        
        return x;
        
        
    }
};