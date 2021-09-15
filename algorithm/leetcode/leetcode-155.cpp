class MinStack {
private:
    stack<int> minValues;
    stack<int> values;
public:
    /** initialize your data structure here. */
    MinStack() {
        minValues = stack<int>();
        values = stack<int>();
    }
    
    void push(int val) {
        values.push(val);
        if(minValues.empty()==true) {
            minValues.push(val);
        }
        else {
            int top = minValues.top();
            if(val <= top) {
                minValues.push(val);
            }
            else {
                minValues.push(top);
            }
        }
    }
    
    void pop() {
        values.pop();
        minValues.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return minValues.top();
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