class Solution {
public:
    /**
     * @param n: the row of the matrix
     * @param m: the column of the matrix
     * @param after: the matrix
     * @return: restore the matrix
     */
    vector<vector<int>> matrixRestoration(int n, int m, vector<vector<int>> &after) {
        // write your code here
        vector<vector<int>> before(n,vector<int>(m,0));
        //before[i,j] = after[i,j] - after[i-1,j] - after[i,j-1] + after[i-1,j-1]
        before[0][0] = after[0][0];
        for( int j = 1; j < m; j++ ) {
             before[0][j] = after[0][j] - after[0][j-1];
        }
        for( int i = 1; i < n; i++ ) {
            before[i][0] = after[i][0] - after[i-1][0];
        }

        for( int i = 1; i < n; i++ ) {
            for( int j = 1; j < m; j++ ) {
                before[i][j] = after[i][j] - after[i-1][j] - after[i][j-1] + after[i-1][j-1];
            }
        }
        return before;
    }
};