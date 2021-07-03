ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *curr=A;
    int count=0;
    if(A==NULL||B=0) return A;
    
    while(curr!=NULL){
        count++;
        curr=curr->next;
    }
    
    if(B>=count){
    A=A->next;
    return A;
    }
    
    int temp=count-B;
    curr=A;
    
    while(temp){
        curr=curr->next
    }
    
    
}
