//first step for quick sort
class Solution {
private:
    void swap(vector<int>& nums,int left,int right)
    {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        return;
    }
public:
    void sortColors(vector<int>& nums) {
        int zeroBoundary = -1;
        int twoBoundary = nums.size();
        int index = 0;
        /* [0,zeroBoundary] define 0
           (zeroBoundary,i] define 1
           [twoBoundary,nums.size()-1] define 2
        */
        while( index < twoBoundary )
        {
            if(nums[index] == 1)
            {
                index++;
            }
            else if(nums[index] == 0)
            {
                swap(nums,zeroBoundary+1,index);
                zeroBoundary++;
                index++;
            }
            else
            {
                // when nums[index] == 2
                swap(nums,index,twoBoundary-1);
                twoBoundary--;
            }
        }
        return;
    }
};