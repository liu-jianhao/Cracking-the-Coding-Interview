class TripleInOne {
    vector<int> data;
    int stackPtr[3];

public:
    TripleInOne(int stackSize) {
        for(int i = 0; i < 3; ++i) {
            stackPtr[i] = stackSize*i;
        }
        this->data = vector<int>(3*stackSize);
    }
    
    void push(int stackNum, int value) {
        if(this->isFull(stackNum)) {
            return;
        }
        this->data[this->stackPtr[stackNum]] = value;
        this->stackPtr[stackNum]++;
    }
    
    int pop(int stackNum) {
        if(this->isEmpty(stackNum)) {
            return -1;
        }
        int value = this->data[this->stackPtr[stackNum]-1];
        this->stackPtr[stackNum]--;
        return value;
    }
    
    int peek(int stackNum) {
        if(this->isEmpty(stackNum)) {
            return -1;
        }
        return this->data[this->stackPtr[stackNum]-1];
    }
    
    bool isEmpty(int stackNum) {
        switch(stackNum) {
        case 0:
            return this->stackPtr[0] == 0;
        case 1:
            return this->stackPtr[1] == this->data.size()/3;
        case 2:
            return this->stackPtr[2] == (this->data.size()/3)*2;
        }
        return true;
    }

    bool isFull(int stackNum) {
        switch(stackNum) {
        case 0:
            return this->stackPtr[0] == this->data.size()/3;
        case 1:
            return this->stackPtr[1] == (this->data.size()/3)*2;
        case 2:
            return this->stackPtr[2] == this->data.size();
        }
        return true;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */