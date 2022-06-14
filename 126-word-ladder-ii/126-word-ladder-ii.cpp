class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mp ; 
        // Record the number of conversions required to reach this string
        vector<vector<string>> ans ;
		//add words to map
        for(const auto w:wordList) 
        {
            mp.insert({w,INT_MAX});
        }
        mp[beginWord]=0;  

		//queue which stores word along sequence till now
        queue<pair<string,vector<string>>> q;
        q.push({beginWord,{beginWord}});
		
        while(!q.empty())
        {
            auto n = q.front() ;
            q.pop() ;
			//find word and sequence
            string w = n.first ;
            auto v=n.second ;
			
			//found one solution, add to result set and continue
            if(w==endWord)
            {
                ans.push_back(v);
                continue;
            }
			//explore possibilities from this word 
			
            for(int i = 0 ; i < w.size() ; i++)
            {
                string t = w ;
                for(char c='a' ; c <= 'z' ; c++)
                {
                    t[i] = c ;
                    if(t==w)
                    {
                        continue ;
                    }
                    if(mp.find(t)==mp.end())
                    {
                        continue ;
                    }
                    if(mp[t]<(int)v.size())
                    {
                        continue ;
                    } 
                    mp[t] = (int)v.size() ;
                    v.push_back(t) ;
                    q.push({t,v}) ;
                    v.pop_back() ;
                }
            }
        }
        return ans ;
    }
};