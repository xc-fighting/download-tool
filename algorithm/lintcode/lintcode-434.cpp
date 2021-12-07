/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

class Solution {
public:


    int findParent(vector<vector<int>>& parent, int r, int c) {
        int cols = parent[0].size();
        int key = r * cols + c;
        if( parent[r][c] == key ) {
            return key;
        }
        int pRow = parent[r][c] / cols;
        int pCol = parent[r][c] % cols;
        int superRoot = findParent(parent, pRow, pCol);
        parent[r][c] = superRoot;
        return superRoot;
    }
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point> &operators) {
        // write your code here
        vector<int> result;
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> parent(n,vector<int>(m,-1));

        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        int numIslands = 0;
        for( int idx = 0; idx < operators.size(); idx++ ) {
            int x = operators[idx].x;
            int y = operators[idx].y;
            if( grid[x][y] == 1 ) {
                result.push_back(numIslands);
                continue;
            }
            else {
                //the position is sea
                numIslands++;
                parent[x][y] = x*m + y;
                grid[x][y] = 1;
                //check in four direction
                for( int i = 0; i < 4; i++ ) {
                    int newx = x + dx[i];
                    int newy = y + dy[i];
                    if( newx >= 0 && newx < n 
                        && newy >= 0 && newy < m 
                        && grid[newx][newy] == 1) {
                         
                         int pNew = findParent(parent,newx,newy);
                         int pCur = findParent(parent,x, y);
                         if( pCur != pNew ) {
                             parent[pNew/m][pNew%m] = pCur;
                             numIslands--;
                         }
                    }
                }
                result.push_back(numIslands);
            }
        }
        return result;
    }
};