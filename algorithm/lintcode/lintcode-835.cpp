class Solution {
public:
    /**
     * @param x: an integer
     * @param y: an integer
     * @return: return an integer, denote the Hamming Distance between two integers
     */  

    int hammingDistance(int x, int y) {
        // write your code here
        int mask = x ^ y;
        int distance = 0;
        while(mask > 0)
        {
           int flag = mask & 1;
           if(flag >0)
           {
               distance++;
           }
           mask = mask >> 1;
        }
        return distance;
    }
};