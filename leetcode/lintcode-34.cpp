/*


Description
According to N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

n <= 10n<=10

Example
Example 1:

Input:

n = 1
Output:

1
Explanation:

1:
1

Example 2:

Input:

n = 4
Output:

2
Explanation:

1:
0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0
2:
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


*/

class Solution {
public:
    /**
     * @param n: The number of queens.
     * @return: The total number of distinct solutions.
     */
    int totalNQueens(int n) {
        // write your code here
        //initialize several map here
        int largest = n -1;
        //row-col
        map<int,bool> diagonal;
        for(int key=(-largest);key<=largest;key++)
        {
            diagonal[key] = false;
        }
        //row+col
        map<int,bool> anti_diagonal;
        for(int key=0;key<=largest*largest;key++)
        {
            anti_diagonal[key] = false;
        }

        map<int,bool> row_map;
        for(int i=0;i<n;i++)
        {
            row_map[i] = false;
        }

        map<int,bool> col_map;
        for(int j=0;j<n;j++)
        {
            col_map[j] = false;
        }

        return getValidBoard(diagonal,anti_diagonal,row_map,col_map,0,n);
        

    }
    
    bool validToAdd(map<int,bool>& diagonal,map<int,bool>& anti_diagonal,
                      map<int,bool>& row_map,map<int,bool>& col_map,int row,int col)
    {
        int diagonal_key = row - col;
        int anti_diagonal_key = row + col;
        if( diagonal[diagonal_key] == true || anti_diagonal[anti_diagonal_key] == true 
            || row_map[row] == true || col_map[col] == true )
        {
            return false;
        }
        return true;

    }

    void set(map<int,bool>& diagonal,map<int,bool>& anti_diagonal,
                      map<int,bool>& row_map,map<int,bool>& col_map,int row,int col)
    {
        int diagonal_key = row - col;
        int anti_diagonal_key = row + col;
        diagonal[diagonal_key] = true;
        anti_diagonal[anti_diagonal_key] = true; 
        row_map[row] = true;
        col_map[col] = true;
    }

    void reset(map<int,bool>& diagonal,map<int,bool>& anti_diagonal,
                      map<int,bool>& row_map,map<int,bool>& col_map,int row,int col)
    {
        int diagonal_key = row - col;
        int anti_diagonal_key = row + col;
        diagonal[diagonal_key] = false;
        anti_diagonal[anti_diagonal_key] = false; 
        row_map[row] = false;
        col_map[col] = false;
    }
    int getValidBoard(map<int,bool>& diagonal,map<int,bool>& anti_diagonal,
                      map<int,bool>& row_map,map<int,bool>& col_map,
                      int curCol,int n)
    {
         if(curCol == n)
         {
             return 1;
         }
         int result = 0;
         for(int row=0;row<n;row++)
         {
            if(validToAdd(diagonal,anti_diagonal,row_map,col_map,row,curCol))
            {
                set(diagonal,anti_diagonal,row_map,col_map,row,curCol);
                result += getValidBoard(diagonal,anti_diagonal,row_map,col_map,curCol+1,n);
                reset(diagonal,anti_diagonal,row_map,col_map,row,curCol);
            }
         }
         return result;
    }


};