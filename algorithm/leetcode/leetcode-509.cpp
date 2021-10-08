class Solution {
public:
    int fib(int n) {
        if( n == 0 ){
            return 0;
        }
        if( n <= 2 ) {
            return 1;
        }
        int prev_one = 1;
        int prev_two = 1;
        for( int input = 3; input <= n; input++ ) {
            int res = prev_one + prev_two;
            prev_one = prev_two;
            prev_two = res;
        }
        return prev_two;
    }
};