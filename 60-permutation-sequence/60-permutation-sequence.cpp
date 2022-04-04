class Solution {
public:
    vector<int> fact;
    vector<int> digit;
    
    void helper(int n, int k, string &ans){
        if(n==1){
            ans+=to_string(digit.back());
        return;
        }
    
    int index=k/fact[n-1];
    
    if(k%fact[n-1]==0)
        index-=1;
    
    ans+=to_string(digit[index]);
    
    digit.erase(digit.begin()+index);
    
    k-=fact[n-1]*index;
    
        helper(n-1,k,ans);
    }
    string getPermutation(int n, int k) {
      fact.push_back(1);
        int f=1;
        
        for(int i=1;i<n;i++){
            f*=i;
            fact.push_back(f);
        }
        
        for(int i=1;i<=n;i++){
            digit.push_back(i);
        }
        
        string ans="";
        
        helper(n,k,ans);
        return ans;
    }
};