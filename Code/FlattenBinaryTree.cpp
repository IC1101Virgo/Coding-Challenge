void helper(TreeNode *A, vector<TreeNode *> &v){
    if(!A)
    return;
    
    v.push_back(A);
    helper(A->left,v);
    helper(A->right,v);
    
    
}
TreeNode* Solution::flatten(TreeNode* A) {
    
    vector<TreeNode *>v;
    
    helper(A,v);
    for(int i=0;i<v.size();i++){
        v[i]->left=NULL;
        v[i]->right=(i==v.size()-1?NULL:v[i+1]);
        
    }
    
    return A;
    
}
