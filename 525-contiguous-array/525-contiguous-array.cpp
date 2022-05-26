class Solution {
public:
    int findMaxLength(vector<int>& A) {
        int n=A.size();
        
        unordered_map<int,int>m;
        int sum=0, l=0;
        
        for(int i=0;i<n;i++){
            A[i]=(A[i]==0)?-1:1;
            
            sum+=A[i];
            
            if(sum==0)
                l=i+1;
            
            else if(m.find(sum)!=m.end()){
                l=max(l,i-m[sum]);
            }
            
             else m[sum]=i;
        }
        
        return l;
    }
};