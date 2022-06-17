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
    void insert(ListNode* head, ListNode* node) {
        while (head->next && head->next->val < node->val) head = head->next;
        node->next = head->next;
        head->next = node;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* new_head = new ListNode(0);

        while (head) {
            ListNode* node = head;
            head = head->next;
            insert(new_head, node);
        }
        
        return new_head->next;
    }
};