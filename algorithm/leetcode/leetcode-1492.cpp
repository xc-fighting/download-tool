class Solution {
public:
    int kthFactor(int n, int k) {
        int order = 0;
        int factor = 1;
        while( factor <= n ) {
           // cout<<factor<<endl;
            
            
            if( ( n % factor ) == 0 ) {
                
                order++;
                
            }
            if( order == k ) {
                return factor;
            }
            factor++;
        }
        return -1;
    }
};