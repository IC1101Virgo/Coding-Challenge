/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head)
            return 0;
        
        ListNode *fast=head, *slow=head;
        
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            
            if(slow==fast){
                return 1;
            }
        }
        
        return 0;
    }
};