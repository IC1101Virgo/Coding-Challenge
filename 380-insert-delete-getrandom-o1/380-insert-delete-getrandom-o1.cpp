class RandomizedSet {
public:
    unordered_map<int,int>s;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val)==s.end()){
            
            s[val]++;
            return true;
        }
        
        else
        return false;
        
    }
    
    bool remove(int val) {
        if(s.find(val)!=s.end()){
            
            s.erase(val);
            return true;
        }
        
        else
        return false;
    }
    
    int getRandom() {
         int num1=rand()%s.size();
        unordered_map<int, int>::iterator it = s.begin();  // position iterator to traverse to the given index as needed (using num1)
        while(num1--)
            it++;
			
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */