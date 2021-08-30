class SortedStack {
    stack<int> s1, s2; // s1降序 s2升序
public:
    SortedStack() {

    }
    
    void push(int val) {
        while(!s2.empty() && s2.top() > val) {
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty() && s1.top() < val) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }
    
    void pop() {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) {
            s1.pop();
        }
    }
    
    int peek() {
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) {
            return s1.top();
        }
        return -1;
    }
    
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */