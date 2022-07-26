class Solution {
public:
    struct Trie{
        Trie *ischild[26];
        bool isword;
        int cnt;
        Trie(){
            for(int i=0;i<26;i++)
                ischild[i]=NULL;
            isword=false;
            cnt=0;
        }
    };
    
    Trie *root;
    
    void insert(Trie *root, string str){
        Trie *curr=root;
        
        for(auto i:str){
            if(curr->ischild[i-'a']==NULL){
                Trie *temp=new Trie();
                curr->ischild[i-'a']=temp;
            }
            
            curr=curr->ischild[i-'a'];
            curr->cnt++;
        }
        
        curr->isword=true;
    }
    
    void search(Trie* root, string str, string &res, int len){
        
        Trie *curr=root;
        
        for(auto i:str){
            if(curr->ischild[i-'a']==NULL)
                break;
            
            if(curr->ischild[i-'a']->cnt== len)
                res+=i;
            
            else break;
            
            curr =curr->ischild[i-'a'];
            
        }
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        Trie *root=new Trie();
        
        for(int i=0;i<strs.size();i++){
            insert(root,strs[i]);
        }
        
        string res="";
        
        search(root,strs[0],res, strs.size());
        
        return res;
    }
};