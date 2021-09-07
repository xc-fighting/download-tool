class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        if(heights.size()==0)
        {
            return 0;
        }
        // write your code here
        int len = heights.size();
        vector<int> leftMaxHeights(len,-1);
        vector<int> rightMaxHeights(len,-1);
        leftMaxHeights[0] = heights[0];
        
        for(int i=1;i<len;i++)
        {
           leftMaxHeights[i] = max(leftMaxHeights[i-1],heights[i]);
        }
        rightMaxHeights[len-1] = heights[len-1];
        for(int i=len-2;i>=0;i--)
        {
            rightMaxHeights[i] = max(rightMaxHeights[i+1],heights[i]);
        }
        
        int result = 0;
        for(int i=1;i<=len-2;i++)
        {
            int borderHeight = min(leftMaxHeights[i],rightMaxHeights[i]);
            result += borderHeight - heights[i];
        }
        return result;

    }
};