class MinStack {
private:
    stack<int>s;
    stack<int>minSt;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        s.push(value);
        if(minSt.empty() || value<=minSt.top()){
            minSt.push(value);
        }
    }
    
    void pop() {
        if(!s.empty()){
            if(s.top()==minSt.top()){
                minSt.pop();
            }
            s.pop();
        }else{
            return;
        }
    }
    
    int top() {
        if(!s.empty()){
            return s.top();
        }else{
            return -1;
        }
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */