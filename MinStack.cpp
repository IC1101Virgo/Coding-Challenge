stack<pair<int,int>> s;
MinStack::MinStack() {
    while(!s.empty())
    s.pop();
}

void MinStack::push(int x) {
    if(s.empty())
    s.push({x,x});
    else
    s.push({x,min(x,s.top().second)});
}

void MinStack::pop() {
    if(!s.empty())
    s.pop();
    
}

int MinStack::top() {
    return s.empty()?-1:s.top().first;
}

int MinStack::getMin() {
    return s.empty()?-1:s.top().second;
}
