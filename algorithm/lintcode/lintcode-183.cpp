class Solution {
public:
    /**
     * @param L: Given n pieces of wood with length L[i]
     * @param k: An integer
     * @return: The maximum length of the small pieces
     */
    bool checkValidLen(vector<int>& input, int woodLen, int k) {
        int NumPieces = 0;
        for( int index = 0; index < input.size(); index++ ) {
             NumPieces += input[index] / woodLen;
        }
        if( NumPieces >= k ) {
            return true;
        }
        return false;
    }
    int woodCut(vector<int> &L, int k) {
        // write your code here
        int maxLen = 0;
        for(int index = 0; index < L.size(); index++ ) {
            maxLen = max(maxLen, L[index]);
        }
        int left = 1;
        int right = maxLen;
        while( left + 1 < right ) {
            int mid = left + (right-left) / 2;
            if( checkValidLen(L,mid,k) == true ) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        if(checkValidLen(L,right,k)) {
            return right;
        }
        if( checkValidLen(L,left,k) ) {
            return left;
        }
        return 0;
    }
};