class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char>> &board, string &word) 
    {
        // write your code here
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> seen(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if( canFind(board,i,j,word,0,seen) )
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool canFind(vector<vector<char>>& board,int curRow,int curCol,
                  string& word,int curIndex,vector<vector<bool>>& seen)
    {
       if(curIndex == word.size() - 1)
       {
           if(board[curRow][curCol] == word[curIndex])
           {
               return true;
           }
           return false;
       }
       if(board[curRow][curCol] != word[curIndex])
       {
           return false;
       }
       int dx[4] = {0,0,1,-1};
       int dy[4] = {1,-1,0,0};
       seen[curRow][curCol] = true;
       for(int i=0;i<4;i++)
       {
           int newr = curRow + dx[i];
           int newc = curCol + dy[i];
           if(newr < 0 || newr >= board.size() 
              || newc < 0 || newc >= board[0].size() 
              || seen[newr][newc] == true )
           {
               continue;
           }
           bool find = canFind(board,newr,newc,word,curIndex+1,seen);
           if( find )
           {
               seen[curRow][curCol] = false;
               return true;
           }
       }
       seen[curRow][curCol] = false;
       return false;
    }
};