class Solution {
public:
    /**
     * @param arr: the map
     * @return:  the smallest target that satisfies from the upper left corner (0, 0) to the lower right corner (n-1, n-1)
     */
    bool dfs(vector<vector<int>>& arr, vector<vector<bool>>& seen, int r, int c, int diff) {
        int rows = arr.size();
        int cols = arr[0].size();
        if( r == (rows - 1) && c == (cols - 1)) {
            return true;
        }
        seen[r][c] = true;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for( int idx = 0; idx < 4; idx++ ) {
            int newr = r + dx[idx];
            int newc = c + dy[idx];
            if( newr >= 0 && newr < rows && newc >= 0 && newc < cols && seen[newr][newc] == false) {
                 int curDiff = abs(arr[newr][newc] - arr[r][c]);
                 if( curDiff <= diff ) {
                     bool ret = dfs(arr,seen, newr, newc, diff);
                     if( ret ) {
                         return true;
                     }
                 }
            }
        }
        seen[r][c] = false;
        return false;
    }
    bool canReach(vector<vector<int>>& arr, int diff) {
         int rows = arr.size();
         int cols = arr[0].size();
         vector<vector<bool>> seen(rows, vector<bool>(cols, false));
         bool ret = dfs(arr,seen,0,0,diff);
         if( ret ) {
             return true;
         }
         return false;
    }
    int mapJump(vector<vector<int>> &arr) {
        // Write your code here.
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for( int r = 0; r < arr.size(); r++ ) {
            for( int c = 0; c < arr[0].size(); c++ ) {
                minValue = min(minValue, arr[r][c]);
                maxValue = max(maxValue, arr[r][c]);
            }
        }
        int minDiff = 1;
        int maxDiff = maxValue - minValue;
        while( minDiff + 1 < maxDiff ) {
            int midDiff = minDiff + ( maxDiff - minDiff ) / 2;
            bool Reach = canReach(arr, midDiff);
            if( Reach ) {
                 maxDiff = midDiff;
            }
            else {
                minDiff = midDiff;
            }
        }
        if( canReach(arr,minDiff) ) {
             return minDiff;
        }
        if( canReach(arr,maxDiff) ) {
             return maxDiff;
        }
        return -1;
    }
};