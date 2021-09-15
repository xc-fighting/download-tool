class Solution {
public:
    int calculate(string s) {
        stack<int> values;
        char op = '+';
        int index = 0;
        while(index < s.size()) {
            if(s[index] ==' ') {
                index++;
                continue;
            }
            if(s[index] >='0' && s[index] <='9') {
                //small loop to get the number
                int number = 0;
                while(index < s.size() && s[index] >= '0' && s[index] <= '9') {
                    number = number*10 + (s[index] - '0');
                    index++;
                }
                if(op == '+') {
                    values.push(number);
                }
                else if(op == '-') {
                    values.push(-number);
                }
                else if(op == '*') {
                    int top = values.top();
                    values.pop();
                    int multiply = top*number;
                    values.push(multiply);
                }
                else {
                    int top = values.top();
                    values.pop();
                    int divide = top/number;
                    values.push(divide);
                }
                
                
            }
            else {
                op = s[index];
                index++;
            }
        }
        int sum = 0;
        while(values.empty()==false) {
           sum += values.top();
           values.pop();
        } 
        return sum;
    }
};