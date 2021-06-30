void minimumBribes(vector<int> A) {
    
    int n=A.size(), count=0;
    int ans=0;
    
    for(int i=0;i<n;i++){
        count=0;
        if((A[i]-(i+1))>0) 
        count=(A[i]-(i+1));
        if(count>2){
        cout<<"Too chaotic"<<endl;
        return;
        }
        for(int j=max(0,A[i]-2);j<i;j++) 
        if(A[j]>A[i]) ans++;
    }
    
    cout<<ans<<endl;
    return;
    
}
