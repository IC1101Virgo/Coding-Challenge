class Solution {
public:
    string getPermutation(int A, int B) {
        vector<int> v;
    
    for(int i=1;i<=A;i++)
    v.push_back(i);
    
    do{
        B--;
    }while(next_permutation(v.begin(),v.end()) && B!=1);
    
    string s="";
    
    for(int i:v){
        s=s+to_string(i);
    }
    
    return s;
    }
};