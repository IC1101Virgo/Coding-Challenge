class Solution {
public:
    string addBinary(string a, string b) {
        
        string answer="";
        int sum=0;
        int x= a.size()-1;
        int y= b.size()-1;
         
        //Trasversing backwards in both the string
        
        while(x>=0||y>=0||sum==1)
        {
            
        //computing sum of last digits
            
            sum+=((x>=0)?a[x]-'0':0);
            sum+=((y>=0)?b[y]-'0':0);
        
        //if sum is 1 or 3 then 1 is added
            
            answer=char(sum % 2+'0') + answer;
        //carry
         
            sum/=2;
            //as backward
        x--;
        y--;
        }
        return answer;
        
    }
};
