if(n==1) return "1";
        
        string a=countAndSay(n-1);
        int count=0;
        string res="";
        
        for(int i=0;i<a.size();i++){
            count++;
            
            if(a[i]!=a[i+1]){
                res+=to_string(count)+a[i];
                count=0;
            }
        }
        
        return res;
    }
