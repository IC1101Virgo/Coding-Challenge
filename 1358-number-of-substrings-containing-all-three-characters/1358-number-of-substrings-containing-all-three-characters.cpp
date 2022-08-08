class Solution {
public:
    bool isok(vector<int> v){
        if(v[0]>=1 && v[1]>=1 && v[2]>=1)
            return 1;
        
        else return 0;
    }
    
    int numberOfSubstrings(string s) {
        int n=s.size();
        
        //unordered_map<int, int> mp;
        int temp=0;
        int i=0, j=0;
        
        vector<int> v(3,0);
        
        while(j<n){
               v[s[j]-'a']++;
            if(!isok(v)){
                j++;
            }
            
            else{
                while(isok(v)){
                temp+=n-j;
                v[s[i]-'a']--;
                i++;
                }
                j++;
            }
        }
        
        return temp;
    }
};