class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> indexStack;
        vector<int> result;
        for( int index = heights.size() - 1; index >= 0; index-- ) {
            int curHeight = heights[index];
            while( indexStack.empty()==false && curHeight > heights[indexStack.top()] ) {
                indexStack.pop();
            }
            if( indexStack.empty() == true ) {
                result.push_back(index);
                indexStack.push(index);
            }
            
        }
        int left = 0;
        int right = result.size() - 1;
        while( left < right ) {
            int temp = result[left];
            result[left] = result[right];
            result[right] = temp;
            left++;
            right--;
        }
        return result;
    }
};