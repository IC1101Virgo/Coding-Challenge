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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next)
            return;
        
        ListNode *temp=head;
        int size=0;
        stack<ListNode*> s;
        
        while(temp){
            s.push(temp);
            size++;
            temp=temp->next;
        }
        
        temp=head;
        
        for(int i=0;i<size/2;i++){
            ListNode *ele=s.top();
            s.pop();
            ele->next=temp->next;
            temp->next=ele;
            temp=temp->next->next;
        }
        
        temp->next=NULL;
        

        
    }
};