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
    ListNode* insertionSortList(ListNode* A) {
        ListNode *p=A->next;
    
    if(p==NULL)
    return A;
    
    while(p!=NULL){
        ListNode *p2=A;
        
        while(p!=p2){
            if(p2->val>p->val)
            swap(p->val,p2->val);
            p2=p2->next;
        }
        p=p->next;
    }
    
    return A;
    }
};