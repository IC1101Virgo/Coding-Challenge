#define ll long long int
ll fun(vector<int> &A,ll mid){
    ll sum=0;
    
    for(int i=0;i<A.size();i++){
    if(A[i]>=mid)
    sum+=(A[i]-mid);
    }
    
    return sum;
}
int Solution::solve(vector<int> &A, int B) {
    ll start=0,end=INT_MIN,mid;
    
    for(int i=0;i<A.size();i++)
    end=max(end, 1ll*A[i]);
    
    while(start<=end){
        mid=start+(end-start)/2;
        
        ll x=fun(A,mid);
        
        if(x==B || start==mid) return mid;
        
        else if(x>B) start=mid;
        
        else
        end=mid;
    }
    
    return mid;
}
