class LRUCache {
public:
    #include<list>
unordered_map<int, list<int>::iterator> um_dll;
unordered_map<int, int> key_val;
int cap;
int curr;
list<int> dll;

void delete_key(int key)
{
    if(key_val.find(key) == key_val.end())
        return;
    dll.erase(um_dll[key]);
    --curr;
    key_val.erase(key);
}

void insert_key_val(int key, int value)
{
    key_val[key] = value;
    dll.push_front(key);
    um_dll[key] = dll.begin();
    ++curr;
}

    LRUCache(int capacity) {
        um_dll.clear();
    key_val.clear();
    dll.clear();
    cap = capacity;
    curr = 0;
    }
    
    int get(int key) {
        if(key_val.find(key) == key_val.end())
    {
        return -1;
    }
    else
    {
        int val = key_val[key];
        delete_key(key);
        insert_key_val(key, val);
        return val;
    }
    }
    
    void put(int key, int value) {
        if(key_val.find(key) != key_val.end())
    {
        delete_key(key);
        insert_key_val(key, value);
    }
    else
    {
        if(curr == cap)
        {
            int least_used = dll.back();
            delete_key(least_used);
            insert_key_val(key, value);
        }
        else
        {
            insert_key_val(key, value);
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