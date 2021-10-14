struct Comparator {
public:
    bool operator()(vector<int>& lhs, vector<int>& rhs) {
        if( lhs[2] < rhs[2] ) {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<bool>> seen( rows, vector<bool>(cols,false) );
        priority_queue<vector<int>,vector<vector<int>>,Comparator> pq;
        
        int curIndex = 0;
        vector<int> tuple = {0,0,matrix[0][0]};
        seen[0][0] = true;
        pq.push(tuple);
        while( curIndex < k - 1 && pq.empty() == false ) {
            vector<int> topElem = pq.top();
            pq.pop();
            int curRow = topElem[0];
            int curCol = topElem[1];
            
            if( curRow + 1 < rows && seen[curRow+1][curCol] == false ) {
                 seen[curRow+1][curCol] = true;
                 vector<int> newtuple = {curRow+1,curCol,matrix[curRow+1][curCol]};
                 pq.push(newtuple);
            }
            if( curCol + 1 < cols && seen[curRow][curCol+1] == false ) {
                 seen[curRow][curCol+1] = true;
                 vector<int> newtuple = {curRow, curCol+1, matrix[curRow][curCol+1]};
                 pq.push(newtuple);
            }
            curIndex++;
        }
        
        vector<int> res = pq.top();
        pq.pop();
        return res[2];
        
    }
};