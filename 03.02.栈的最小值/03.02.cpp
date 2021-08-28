class MinStack {
    stack<int> data;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
    
    }
    
    void push(int x) {
        this->data.push(x);
        if (this->minStack.size() == 0) {
            this->minStack.push(x);
        } else {
            this->minStack.push(min(this->minStack.top(), x));
        }
    }
    
    void pop() {
        this->data.pop();
        this->minStack.pop();
    }
    
    int top() {
        return this->data.top();
    }
    
    int getMin() {
        return this->minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */