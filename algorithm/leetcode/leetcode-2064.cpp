class Solution {
public:
    bool canDistribute(vector<int>& quantities, int max, int n) {
        int usage = 0;
        for(int index = 0; index < quantities.size(); index++ ) {
            int num = quantities[index] / max;
            if( quantities[index] % max != 0 ) {
                num++;
            }
            usage += num;
        }
        if( usage > n ) {
            return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int max = 0;
        for( int index = 0; index < quantities.size(); index++ ) {
             if( quantities[index] > max ) {
                 max = quantities[index];
             }
        }
        int left = 1;
        int right = max;
        while(left + 1 < right) {
            int mid = left + (right-left) / 2;
            if(canDistribute(quantities,mid,n) == false ) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        if( canDistribute(quantities,left,n) ) {
            return left;
        }
        return right;
    }
};
