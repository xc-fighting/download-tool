class Solution {
public:
    int rob(vector<int>& nums) {
        int houses = nums.size();
        vector<int> memo(houses,-1);
        return maxMoney(nums,memo,0);
    }
    
    int maxMoney(vector<int>& nums, vector<int>& memo, int curHouse) {
        if( curHouse >= nums.size() ) {
            return 0;
        }
        if( memo[curHouse] != -1 ) {
            return memo[curHouse];
        }
        //rob the currentHouse
        int instantMoney = nums[curHouse];
        int candidate1 = instantMoney + maxMoney(nums,memo, curHouse + 2);
        //not rob the current house
        int candidate2 = maxMoney(nums,memo,curHouse + 1);
        memo[curHouse] =  max( candidate1, candidate2 );
        return memo[curHouse];
    }
};