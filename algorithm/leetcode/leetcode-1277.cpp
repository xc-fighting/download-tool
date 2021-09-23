//TLE solution
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        int len = min(height,width);
        vector<vector<vector<int>>> memo(height,vector<vector<int>>(width,vector<int>(len+1,0)));
        
        //memo[i][j][k] represent whether there is a square end with (i,j) with width of k
        // memo[i][j][k] depends on memo[i-1][j][k-1] memo[i][j-1][k-1] memo[i-1][j-1][k-1] both 1
        // then memo[i][j][k] = 1
        // else when i==0 || j = 0 memo[i][j][k] = 0
         int result = 0;
        for( int row = 0; row < height; row++ ) {
            
            for( int col = 0; col < width; col++ ) {
                 if( matrix[row][col] == 1 ) {
                     memo[row][col][1] = 1;
                     result++;
                 }
                 
            }
        }
        
       
        for( int k = 2; k <= len; k++ ) {
            
            for( int row = 0; row < height; row++ ) {
            
                 for(int col = 0; col < width; col++ ) {
                     
                      if(row == 0 || col == 0 || matrix[row][col] == 0 ) {
                           continue;
                      }
                     
                      int leftValid = memo[row][col-1][k-1];
                      int topValid = memo[row-1][col][k-1];
                      int topleftValid = memo[row-1][col-1][k-1];
                      if( leftValid == 1 && topValid == 1 && topleftValid == 1 ) {
                           memo[row][col][k] = 1;
                           result++;
                      }
                      else {
                           memo[row][col][k] = 0;
                      }
                 
                 }
            }
        }
        
     /*   int result = 0;
        for( int k = 1; k <= len; k++ ) {
            
            for( int row = 0; row < height; row++ ) {
                 
                for( int col = 0; col < width; col++ ) {
                     if( memo[row][col][k] == 1 ) {
                       //  cout<<row<<":"<<col<<"->"<<k<<endl;
                         result++;
                     }
                }
            }
        } */
        
        return result;
        
    }
};

//solution
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<vector<int>> memo(height,vector<int>(width,0));
        // memo[i][j] represent the longest width of the square end with i,j
        for( int row = 0; row < height; row++ ) {
            for( int col = 0; col < width; col++ ) {
                
                if(matrix[row][col] == 1) {
                    memo[row][col] = 1;
                }
            }
        }
        
        for( int row = 0; row < height; row++ ) {
            for( int col = 0; col < width; col++ ) {
                
                if( row ==0 || col == 0 || matrix[row][col] == 0 ) {
                     continue;
                }
                
                memo[row][col] = 1 + min(memo[row-1][col],min(memo[row][col-1],memo[row-1][col-1]));
            }
        }
        
        int result = 0;
        for( int row = 0; row < height; row++ ) {
            for( int col = 0; col < width; col++ ) {
                result += memo[row][col];
            }
        }
        
        return result;
        
    }
};