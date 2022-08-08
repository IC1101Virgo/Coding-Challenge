class Trie {
    


    
public:
    struct TrieNode{
    TrieNode *ischild[26];
    bool isword;
    
    TrieNode(){
        for(int i=0; i<26; i++){
            ischild[i]=NULL;
        }
        
        isword=false;
    }
    
};
TrieNode* root;
    
    Trie() {
         root=new TrieNode();
    }
    
   
    
    void insert(string word) {
        TrieNode *curr=root;
        
        for(auto x:word){
            if(curr->ischild[x-'a']==NULL){
                TrieNode *temp=new TrieNode();
                curr->ischild[x-'a']=temp;
            }
            
            curr=curr->ischild[x-'a'];
        }
        
        curr->isword=true;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        
        for(auto x:word){
            if(curr->ischild[x-'a']){
                
                curr=curr->ischild[x-'a'];
            }
            
            else return 0;
        }
        
        return curr->isword;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        
        for(auto x:prefix){
            if(curr->ischild[x-'a']){
                
                curr=curr->ischild[x-'a'];
            }
            
            else return 0;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */