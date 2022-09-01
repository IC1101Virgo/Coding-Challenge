class Solution {
public:
     vector<string> ans;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    
    class trie{
        public:
        bool fl=0;
        trie *arr[26];
    };
    
    void insert(string &word, trie *root){
        trie *cur=root;
        
        for(int i=0; i<word.size(); ++i){
            int idx = word[i]-'a';
            if(!cur->arr[idx]){
                cur->arr[idx] = new trie();
            }
            cur=cur->arr[idx];
        }
        cur->fl = true;
        return;
    }
    
    bool isvalid(int i, int j, vector<vector<char>>& b){
        int n=b.size(), m=b[0].size();
        
        if(i>=n || i<0||j>=m||j<0||b[i][j]=='*')
            return false;
        
        return true;
    }
    
    void search(vector<vector<char>>& board, int x, int y, trie *root, string &str){
      if(board[x][y]=='*') return;
        
        int idx = board[x][y]-'a';
        if(!root->arr[idx]) return;
        
        str.push_back(board[x][y]);
        
        char ch = board[x][y];
        board[x][y]='*';
        
        if(root->arr[idx]->fl){
            ans.push_back(str);
            root->arr[idx]->fl = false;
        }
        
        for(int i=0;i<4;++i){
            int x1 = x+dx[i], y1 = y+dy[i];
            if(isvalid(x1,y1,board)) search(board,x1,y1,root->arr[idx],str);
        }
        
        board[x][y]=ch;
        str.pop_back();
        return;
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        int n=b.size(), m=b[0].size();
        trie *root=new trie();
        string str="";
        
        for(auto &x:w)
            insert(x,root);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                search(b,i,j,root,str);
            }
        }
        
        return ans;
        
    }
};