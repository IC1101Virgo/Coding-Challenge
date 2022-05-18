class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        
        int i=0;
        
        while(i<n && s[i]==' '){
            i++;
        }
        
         if(isalpha(s[i])){
            return 0;
        }
        
        int flag=1;
        
        if(s[i]=='+')
        i++;
        
       else if(s[i]=='-')
        {
            flag=-1;
            i++;
        }
        
        long long sum=0;
        
        while(isdigit(s[i]) && i<n){
          
              sum=sum*10+(s[i]-'0');
              
            
            if(sum>INT_MAX|| sum<INT_MIN)
            {
                if(flag==-1)
                    return INT_MIN;
                
                else return INT_MAX;
            }
            
           i++; 
        }
        
        return flag*sum;
        
        
    }
};