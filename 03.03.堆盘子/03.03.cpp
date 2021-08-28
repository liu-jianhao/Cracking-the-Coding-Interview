class StackOfPlates {
public:
    StackOfPlates(int cap) {
        capacity = cap;
    }
    
    void push(int val) {
        if (capacity == 0) {
            // 如果capacity为0，直接return
            return;
        }
        if (stks.empty() || stks.back().size() == capacity) {
            // 当前vector为空或当前栈满，新增一个栈
            stks.emplace_back(stack<int>());
        }
        stks.back().push(val);
    }
    
    int pop() {
        if (capacity == 0 || stks.empty()) {
            // capacity为0或当前vector为空，直接return -1
            return -1;
        }
        int res = stks.back().top();
        stks.back().pop();
        if (stks.back().empty()) {
            // 如果最后一个栈为空，需要弹出最后一个栈
            stks.pop_back();
        }
        return res;
    }
    
    int popAt(int index) {
        if (capacity == 0 || index >= stks.size() || stks[index].empty()) {
            // capacity为0或下标越界或当前栈空，直接return -1
            return -1;
        }
        int res = stks[index].top();
        stks[index].pop();
        if (stks[index].empty()) {
            // 如果当前栈空，最后删除当前栈
            stks.erase(stks.begin() + index);
        }
        return res;
    }
private:
    vector<stack<int>> stks;
    int capacity;
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */