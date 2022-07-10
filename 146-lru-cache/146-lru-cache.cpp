class LRUCache {
public:
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>m;
    int s;
    
    void refresh(int key,int value){
        l.erase(m[key]);
        l.push_front({key,value});
        m[key]=l.begin();
    }
    LRUCache(int capacity) {
        s=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            int val=(*m[key]).second;
            refresh(key,val);
            return val;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            refresh(key,value);
        }
        
        else{
            l.push_front({key,value});
            m[key]=l.begin();
            
            if(m.size()>s){
                m.erase(l.back().first);
                l.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */