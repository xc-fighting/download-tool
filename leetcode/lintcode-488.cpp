class Solution {
public:
    /**
     * @param n: An integer
     * @return: true if this is a happy number or false
     */
    int getHappy(int input)
    {
        int result = 0;
        int temp = input;
        while(temp != 0)
        {
            int digit = temp % 10;
            temp = temp / 10;
            result += digit*digit;
        }
        return result;
    }
    bool isHappy(int n) {
        // write your code here
        unordered_set<int> seen;
        int current = n;
        seen.insert(current);
        while(current != 1)
        {
            int nextHappy = getHappy(current);
            if(seen.find(nextHappy) != seen.end())
            {
                return false;
            }
            seen.insert(nextHappy);
            current = nextHappy;
        }
        return true;
    }
};