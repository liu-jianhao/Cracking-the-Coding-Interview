class MyQueue {
    stack<int> inStack, outStack;

    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        this->inStack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(this->outStack.empty()) {
            this->in2out();
        }
        int x = this->outStack.top();
        this->outStack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(this->outStack.empty()) {
            this->in2out();
        }
        return this->outStack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return this->inStack.empty() && this->outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */