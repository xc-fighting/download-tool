class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if( nums.size() < 3 ) {
            return vector<vector<int>>();
        }
        
        sort( nums.begin(), nums.end() );
        int leftIndex = 0;
        vector<vector<int>> result;
        while( leftIndex < nums.size() - 2 ) {
            
            if( leftIndex > 0 && nums[leftIndex] == nums[leftIndex-1] ) {
                leftIndex++;
                continue;
            }
            
            int leftVal = nums[leftIndex];
            int targetVal = -leftVal;
            
            int start = leftIndex + 1;
            int end = nums.size() - 1;
            while( start < end ) {
                int sum = nums[start] + nums[end];
                if( sum < targetVal ) {
                    start++;
                }
                else if( sum > targetVal ) {
                    end--;
                }
                else {
                    vector<int> triplets(3,-1);
                    triplets[0] = nums[leftIndex];
                    triplets[1] = nums[start];
                    triplets[2] = nums[end];
                    result.push_back(triplets);
                    start++;
                    end--;
                    while( start < end && nums[start] == nums[start-1] ) {
                        start++;
                    }
                    while( end  > start && nums[end+1] == nums[end] ) {
                        end--;
                    }
                }
            }
            leftIndex++;
        }
        return result;
    }
};