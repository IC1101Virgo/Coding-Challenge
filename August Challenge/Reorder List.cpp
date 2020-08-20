class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* penultimate;
        while (head && head->next && head->next->next) {
            penultimate = head;
            while (penultimate->next->next) penultimate = penultimate->next;
            
            penultimate->next->next = head->next;
            head->next = penultimate->next;
            
            penultimate->next = NULL;
            head = head->next->next;
        }
    }
};