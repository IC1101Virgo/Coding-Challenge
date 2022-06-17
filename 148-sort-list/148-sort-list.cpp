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
    ListNode *mergelist(ListNode *l1,ListNode *l2){
        ListNode *x=new ListNode(0);
        ListNode *temp=x;
        
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                x->next=l1;
                l1=l1->next;
            }
            
            else{
                x->next=l2;
                l2=l2->next;
            }
            
            x=x->next;
        }
        
        if(l1!=NULL){
            x->next=l1;
            l1=l1->next;
        }
        
        if(l2!=NULL){
            x->next=l2;
            l2=l2->next;
        }
        
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        // 2 pointer appraoach / turtle-hare Algorithm (Finding the middle element)
        while(fast !=  NULL && fast -> next != NULL)
        {
            temp = slow;
            slow = slow->next;          //slow increment by 1
            fast = fast ->next ->next;  //fast incremented by 2
            
        }   
        temp -> next = NULL;            //end of first left half
        
        ListNode* l1 = sortList(head);    //left half recursive call
        ListNode* l2 = sortList(slow);    //right half recursive call
        
        return mergelist(l1, l2);         //mergelist Function call
    }
};