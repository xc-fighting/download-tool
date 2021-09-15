class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowMap = vector<vector<int>>(9,vector<int>(10,0));
        vector<vector<int>> colMap = vector<vector<int>>(9,vector<int>(10,0));
        vector<vector<int>> boxMap = vector<vector<int>>(9,vector<int>(10,0));
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j]=='.') {
                    continue;
                }
                int digit = board[i][j] - '0';
                rowMap[i][digit]++;
                colMap[j][digit]++;
                int boxRow = i/3;
                int boxCol = j/3;
                int boxNumber = boxRow*3 + boxCol;
                boxMap[boxNumber][digit]++;
                if(rowMap[i][digit] > 1 || colMap[j][digit] > 1 || boxMap[boxNumber][digit] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};