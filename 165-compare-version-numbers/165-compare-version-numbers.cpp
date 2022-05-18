class Solution {
public:
    int compareVersion(string A, string B) {
        unsigned long long int a=0,b=0;
    int i=0,j=0;
        
    while(i<A.size() || j<B.size()){
        while(i<A.size() && A[i]!='.'){
            a+=a*10+(A[i]-'0');
            i++;
        }
        
        while(j<B.size() &&B[j]!='.'){
            b+=b*10+(B[j]-'0');
            j++;
        }
        
        if(a>b) return 1;
        else if(b>a) return -1;
        
        a=0;b=0;
        i++;j++;
    }
    
    return 0;
    }
};