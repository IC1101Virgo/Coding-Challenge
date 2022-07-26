class Solution {
public:
    void makelps(const string nee, int m, int lps[]){
    int len=0, i=1;
    lps[0]=0;
    
    while(i<m){
        if(nee[len]==nee[i]){
            len++;
            lps[i]=len;
            i++;
        }
        
        else{
            if(len!=0){
                len=lps[len-1];
            }
            
            else 
            {   lps[i]=0;
                i++;
            }
        }
    }
    
    return;
}
    int strStr(string hay, string nee) {
        int n=hay.size(), m=nee.size();
    
    int lps[m];
    
    makelps(nee,m,lps);
    
    int i=0, j=0;
    int c=0;
    
    while(i<n){
        if(hay[i]==nee[j]){
            i++;
            j++;
        }
        
        if(j==m){
            c=1;
            break;
           // j=lps[j-1];
        }
        
        if(i<n && hay[i]!=nee[j]){
            if(j!=0)
            j=lps[j-1];
            
            else{
                i++;
            }
        }
    }
    
    return c==1?i-j:-1;
    }
};