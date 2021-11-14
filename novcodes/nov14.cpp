class CombinationIterator {
public:
    vector<string> v;
    int pos=0;
    
    void helper(string &s, int len, int pos, string &op){
        if(pos==s.size()){
            if(len==op.size())
                v.push_back(op);
            return;
        }
        
        op.push_back(s[pos]);
        helper(s,len,pos+1,op);
        op.pop_back();
        helper(s,len,pos+1,op);
    }
    
    CombinationIterator(string chara, int comb) {
        string op="";
        helper(chara, comb, 0, op);
        
    }
    
    string next() {
        string ans= v[pos++];
        return ans;
    }
    
    bool hasNext() {
        return pos<v.size();
    }
};
