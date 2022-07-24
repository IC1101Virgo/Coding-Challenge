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
    ListNode* merge(ListNode *a, ListNode *b){
        ListNode *x=new ListNode(0);
        ListNode *temp=x;
        
        while(a!=NULL && b!=NULL){
            if(a->val<=b->val)
            {
                x->next=a;
                a=a->next;
            }
            
            else{
                x->next=b;
                b=b->next;
            }
            
            x=x->next;
        }
        
        while(a!=NULL){
            x->next=a;
            a=a->next;
            x=x->next;
        }
        
        while(b!=NULL){
            x->next=b;
            b=b->next;
            x=x->next;
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
        
        return merge(l1, l2);     
    }
};