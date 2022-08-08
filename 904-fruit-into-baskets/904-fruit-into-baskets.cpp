class Solution {
public:
    
    int totalFruit(vector<int>& fruits) {
        long long n=fruits.size();
        
        unordered_map<long long,long long> m;
        
        long long i=0, j=0;
        long long ans=0;
        
        while(j<n){
           
            m[fruits[j]]++;
            
            while(m.size()>2){
                
                if(m[fruits[i]]==1){
                    m.erase(fruits[i]);
                }
                
                else{
                    m[fruits[i]]--;
                }
                
                i++;
            }
            
            ans=max(ans,j-i+1);
            j++;
            
        }
        
        return ans;
    }
};