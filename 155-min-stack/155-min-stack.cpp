class MinStack {
public:
    stack<pair<int,int>> s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        int x;
        if(!s.empty()){
            x=s.top().second;
            s.push({val,min(x,val)});
        }
        
        else s.push({val,val});
    }
    
    void pop() {
        if(!s.empty())
            s.pop();
    }
    
    int top() {
        if(!s.empty()){
            int x=s.top().first;
            return x;
            
        }
        
        else return -1;
        
    }
    
    int getMin() {
        if(!s.empty()){
            int x=s.top().second;
            return x;
            
        }
        
        else return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */