class Solution {
public:
    vector<vector<string>> res;
    
    struct Trie{
        bool isword;
        Trie* ischild[26];
        vector<int> mark;
        
        Trie(){
             for(int i=0;i<26;i++)
                 ischild[i]=NULL;
            
            isword=false;
            
        }
    };
    
    Trie* root;
    
    void insert(Trie* root, string str, int ind){
        Trie* curr=root;
        
        for(auto i:str){
            if(curr->ischild[i-'a']==NULL){
                Trie *x=new Trie();
                curr->ischild[i-'a']=x;
            }
            
            curr=curr->ischild[i-'a'];
           curr->mark.push_back(ind);
        }
        
        
    }
    
    void search(Trie *root, string str,vector<string>& pro){
        Trie *curr=root;
        
        for(auto i:str){
            if( curr->ischild[i-'a'] ){
                curr=curr->ischild[i-'a'];
                vector<string> temp;
                for(auto j:curr->mark){
                    temp.push_back(pro[j]);
                }
                
                sort(temp.begin(),temp.end());
                
                vector<string>ans;
                
                for(int i=0; i<3; i++){
                    if(i == temp.size())break;
                    ans.push_back(temp[i]);
                }
                
                
                res.push_back(ans);
            }else{
                res.push_back({});
                curr = new Trie();
            }
        }
        
    
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& pro, string searchWord) {
        res.clear();
        
        root = new Trie();
        
        for(int i=0;i<pro.size();i++){
            insert(root,pro[i],i);
        }
        
        search(root,searchWord,pro);
        
        return res;
        
    }
};