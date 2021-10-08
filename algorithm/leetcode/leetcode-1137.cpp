class Solution {
public:
    int tribonacci(int n) {
        if( n == 0 ) {
            return 0;
        }
        if( n == 1 ) {
            return 1;
        }
        if( n == 2 ) {
            return 1;
        }
        int T0 = 0;
        int T1 = 1;
        int T2 = 1;
        
        for( int input = 3; input <= n; input++ ){
            int res = T0 + T1 + T2;
            T0 = T1;
            T1 = T2;
            T2 = res;
        }
        
        return T2;
        
    }
};