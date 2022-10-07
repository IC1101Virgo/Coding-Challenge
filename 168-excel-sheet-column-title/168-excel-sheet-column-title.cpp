class Solution {
public:
    string convertToTitle(int c) {
        if(c<=0)
            return "";
        
        string ans="";
        
        while(c>0){
            char ch='A'+(c-1)%26;
            ans=ch+ans;
            c=(c-1)/26;
        }
        
        return ans;
    }
};