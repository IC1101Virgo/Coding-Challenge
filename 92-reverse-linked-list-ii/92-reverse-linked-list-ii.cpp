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
    ListNode* reverseBetween(ListNode* A, int B, int C) {
        if(B!=1){
        A->next=reverseBetween(A->next,B-1,C-1);
        return A;
    }
    
    else{
        ListNode *prev=NULL, *curr=A, *next;
        int count=0;
        
        while(count<C){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        A->next=curr;
        return prev;
    }  
    }
};