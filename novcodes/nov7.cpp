class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size(), m=num2.size();
        string res(n+m,'0');
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int num=(num1[i]-'0')*(num2[j]-'0')+res[i+j+1]-'0';
                res[i+j+1]=num%10+'0';
                res[i+j]+=num/10;
            }
        }
        
        for(int i=0;i<res.size();i++){
            if(res[i]!='0') return res.substr(i);
        }
        
        return "0";
    }
};
