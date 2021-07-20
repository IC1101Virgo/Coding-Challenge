class Solution {
public:
    int canBeTypedWords(string text, string bro) {
     bool badword=0;
        int ans=0;
        
        int n=text.length(), m=bro.length();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text[i]==bro[j])
                    badword=1;
                }
            
            if(text[i]==' ' || i==n-1){
                if(badword==0)
                    ans++;
                else badword=0;
            }
        }
        
        return ans;
    }
};
