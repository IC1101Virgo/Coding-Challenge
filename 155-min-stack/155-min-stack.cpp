class MinStack {
public:
    stack<pair<int,int>>s;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty())
            s.push({val,val});
        
        else{
            int mini=min(val,s.top().second);
            s.push({val,mini});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        auto x=s.top();
        return x.first;
    }
    
    int getMin() {
        auto x=s.top();
        return x.second;
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