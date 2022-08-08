class Solution {
public:
    
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        
        unordered_map<int,int> m;
        
        int i=0, j=0;
        int ans=0;
        
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