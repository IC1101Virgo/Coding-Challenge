int height(TreeNode *A){
    if(!A) return 0;
    
    return 1+max(height(A->left),height(A->right));
}
int Solution::isBalanced(TreeNode* A) {
    if(!A) return 1;
    
    if(abs(height(A->left)-height(A->right))>1)
    return 0;
    
    return isBalanced(A->left) && isBalanced(A->right);
    
}
