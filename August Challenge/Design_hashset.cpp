class Buckets{
        private int itemsNum;
        private int items[];
        
        public Buckets(){
            itemsNum = 1001;
            items = new int[itemsNum];
            init();
        }
        
        public void init(){
            for(int i = 0; i < itemsNum; i++)
                items[i] = -1;
        }
        
        public void setItem(int key,int value){
            int index = hashItem(key);
            items[index] = value;
        }
        
        public int getItem(int key){
            int index = hashItem(key);
            return items[index];
        }
        public int hashItem(int key){
            return key / bucketsNum;
        }
    }
    
    private int bucketsNum;
    private Buckets buckets[];
    /** Initialize your data structure here. */
    public MyHashSet() {
        bucketsNum = 1000;
        buckets = new Buckets[bucketsNum];
    }
    
    public int hashBucket(int key){
        return key % bucketsNum;
    }
    public void add(int key) {
        int bucketID = hashBucket(key);
        if(buckets[bucketID] == null) buckets[bucketID] = new Buckets();
        buckets[bucketID].setItem(key, key);
    }
    
    public void remove(int key) {
        int bucketID = hashBucket(key);
        if(contains(key)) buckets[bucketID].setItem(key, -1);
    }
    
    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int bucketID = hashBucket(key);
        return buckets[bucketID] != null && buckets[bucketID].getItem(key) != -1;
    }