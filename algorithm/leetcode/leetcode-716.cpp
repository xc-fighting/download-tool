class MaxStack {
private:
    stack<int> maxValues;
    stack<int> values;
public:
    /** initialize your data structure here. */
    MaxStack() {
        maxValues = stack<int>();
        values = stack<int>();
    }
    
    void push(int x) {
        values.push(x);
        if(maxValues.empty() == true) {
            maxValues.push(x);
        }
        else {
            int top = maxValues.top();
            if(x >= top) {
                maxValues.push(x);
            }
            else {
                maxValues.push(top);
            }
        }
    }
    
    int pop() {
        int val = values.top();
        values.pop();
        maxValues.pop();
        return val;
    }
    
    int top() {
        return values.top();
    }
    
    int peekMax() {
        return maxValues.top();
    }
    
    int popMax() {
        stack<int> tempbuffer;
        int currentMax = maxValues.top();
        while(values.empty()==false && values.top() != currentMax) {
            tempbuffer.push(values.top());
            values.pop();
            maxValues.pop();
        }
        //pop the maxValue
        values.pop();
        maxValues.pop();
        while(tempbuffer.empty()==false) {
            push(tempbuffer.top());
            tempbuffer.pop();
        }
        return currentMax;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */