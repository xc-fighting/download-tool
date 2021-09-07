class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        int rows = matrix.size();
        int cols = matrix[0].size();
        return searchInRegion(matrix,0,0,rows-1,cols-1,target);
    }

    int searchInRegion(vector<vector<int>>& matrix,int topRow,int topCol,int bottomRow,int bottomCol,int target)
    {
        if(topRow > bottomRow || topCol > bottomCol)
        {
            return 0;
        }
        
        int result = 0;
        int midRow = topRow + (bottomRow - topRow)/2;
        int midCol = topCol + (bottomCol - topCol)/2;
        if(matrix[midRow][midCol] == target)
        {
            result++;
            result += searchInRegion(matrix,midRow+1,topCol,bottomRow,midCol,target);
            result += searchInRegion(matrix,topRow,midCol+1,midRow-1,bottomCol,target);
        }
        else if(matrix[midRow][midCol] < target)
        {
            result += searchInRegion(matrix,topRow,midCol+1,bottomRow,bottomCol,target);
            result += searchInRegion(matrix,midRow+1,topCol,bottomRow,midCol,target);
        }
        else 
        {
            result += searchInRegion(matrix,topRow,topCol,midRow-1,bottomCol,target);
            result += searchInRegion(matrix,midRow,topCol,bottomRow,midCol-1,target);
        }
        return result;

    }
};