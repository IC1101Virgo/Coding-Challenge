class Solution {
public:
    int evalRPN(vector<string>& A) {
       int n=A.size();
    stack<string> s;
    
    for(int i=0;i<n;i++){
        
        if(A[i]=="/" ||A[i]=="+" || A[i]=="-" ||A[i]=="*"){
            int a=stoi(s.top());
            s.pop();
            int b=stoi(s.top());
            s.pop();
            
            if(A[i]=="/"){
                s.push(to_string(b/a));
            }
            
            if(A[i]=="*"){
                s.push(to_string(b*a));
            }
            
            if(A[i]=="+"){
                s.push(to_string(b+a));
            }
            
            if(A[i]=="-"){
                s.push(to_string(b-a));
            }
        }
            
         else s.push(A[i]);
        }
        
        return stoi(s.top());
    }
};