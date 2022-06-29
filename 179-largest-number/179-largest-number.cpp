class Solution {
public:
     static bool compare(int a, int b){
    string x=to_string(a), y=to_string(b);
    
    return (x+y)>(y+x);
}
    string largestNumber(vector<int>& A) {
         sort(A.begin(),A.end(),compare);
    
    string res="";
    int count=0;
    
    for(int i=0;i<A.size();i++){
        res+=to_string(A[i]);
        
        if(A[i]==0)
        count++;
    }
    
    return count==A.size()? "0":res;
    }
};