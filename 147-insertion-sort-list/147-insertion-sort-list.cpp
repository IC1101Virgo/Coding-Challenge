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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *ptr=head->next;
        
        if(ptr==NULL)
            return head;
        
        while(ptr){
            ListNode *p=head;
            
            while(p!=ptr){
                if(p->val>ptr->val)
                    swap(p->val,ptr->val);
                p=p->next;
            }
            
            ptr=ptr->next;
        }
        
        return head;
    }
};