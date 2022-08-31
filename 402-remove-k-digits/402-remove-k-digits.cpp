class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char>s;
        
        
        //s.push(num[0]);
        
        for(int i=0; i<n; i++){
            while(k>0 && !s.empty() && s.top()>num[i]){
                s.pop();
                k--;
            }
            
            s.push(num[i]);
            
            if(s.size()==1 && s.top()=='0')
                s.pop();
        }
        
        
        while(k>0 && !s.empty()){
            s.pop();
            k--;
        }
        
        string res="";
        
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return res.size()==0? "0" : res;
        
    }
};