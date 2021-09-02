class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    vector<int> generate(int bitsum)
    {
            vector<int> result(2,0);
            if(bitsum == 0)
            {
                result[0] = 0;
                result[1] = 0;
            }
            else if(bitsum == 1)
            {
                result[0] = 1;
                result[1] = 0;
            }
            else if(bitsum == 2)
            {
                result[0] = 0;
                result[1] = 1;
            }
            else if(bitsum == 3)
            {
                result[0] = 1;
                result[1] = 1;
            }
            return result;
    }
    string addBinary(string &a, string &b) {
        // write your code here
        int lastIndexA = a.size() - 1;
        int lastIndexB = b.size() - 1;
        int carry = 0;
        string result = "";
        while( lastIndexA >=0 && lastIndexB >= 0 )
        {
            int bitA = a[lastIndexA] - '0';
            int bitB = b[lastIndexB] - '0';
            int bitsum = bitA + bitB + carry;
            vector<int> ret = generate(bitsum);
            result = to_string(ret[0]) + result;
            carry = ret[1];
            lastIndexA--;
            lastIndexB--;
        }
        while(lastIndexA >= 0)
        {
            int bitA = a[lastIndexA] - '0';
            int bitsum = bitA + carry;
            vector<int> ret = generate(bitsum);
            result = to_string(ret[0]) + result;
            carry = ret[1];
            lastIndexA--;
        }
        while(lastIndexB >= 0)
        {
            int bitB = b[lastIndexB] - '0';
            int bitsum = bitB + carry;
            vector<int> ret = generate(bitsum);
            result = to_string(ret[0]) + result;
            carry = ret[1];
            lastIndexB--;
        }

        if(carry == 1)
        {
            result = "1" + result;
        }
        return result;
    }
};