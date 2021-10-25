class MinStack {
public:
    stack<pair<int,int>> s;
    
    MinStack() {
       while(!s.empty())
           s.pop();
    }
    
    void push(int val) {
        if(!s.empty()){
            s.push({val,min(val,s.top().second)});
        }
        
        else s.push({val,val});
    }
    
    void pop() {
        if(!s.empty())
        {
            s.pop();
        }
    }
    
    int top() {
        if(!s.empty())
            return s.top().first;
        else
            return -1;
    }
    
    int getMin() {
        if(!s.empty())
            return s.top().second;
        else return -1;
    }
};
