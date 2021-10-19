class Solution {
public:
    /*
     * @param x: An integer
     * @return: An integer
     */
    int swapOddEvenBits(int x) {
        // write your code here
        unsigned int highbits = x & (0xaaaaaaaa);
        unsigned int lowbits = x & (0x55555555);
        return ( highbits >> 1 ) | ( lowbits << 1 );
    }
};