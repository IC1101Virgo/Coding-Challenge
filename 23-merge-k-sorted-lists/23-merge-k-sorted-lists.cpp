class Solution {
public:
    ListNode* helper(ListNode *a, ListNode *b){
        ListNode *head=NULL;
        
        if(!a)
            return b;
        
        if(!b)
            return a;
        
        if(a->val<=b->val){
            head=a;
            head->next=helper(a->next,b);
        }
        
        else{
            head=b;
            head->next=helper(a,b->next);
        }
        
        return head;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        
        if(n==0)
            return NULL;
        
        ListNode *head= lists[0];
        
        for(int i=1;i<n;i++){
            head=helper(head,lists[i]);
        }
        
        return head;
    }
};