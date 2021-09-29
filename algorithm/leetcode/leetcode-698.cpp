class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int len = nums.size();
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
        }
        int target = sum/k;
        vector<bool> used(len,false);
        return canPartition(nums,used,target,k);
    }
    
    bool canPartition(vector<int>& nums, vector<bool> used, 
                      int target, int partitionLeft) {
        if( partitionLeft == 0 ) {
             for(int i = 0; i < used.size(); i++) {
                 if(used[i] == false) {
                     return false;
                 }
             }
             return true;
        }
        
        if( partitionLeft == 1 ) {
            int sum = 0;
            for( int index = 0; index < nums.size(); index++ ) {
                 if( used[index] == false ) {
                     sum += nums[index];
                 }
                 
            }
            if( sum == target ) {
                return true;
            }
        }
        
        vector<vector<int>> subsets = findSubSets(nums,used,0,target);
        if(subsets.size() == 0) {
            return false;
        }
        for( int index = 0; index < subsets.size(); index++ ) {
             vector<int> subset = subsets[index];
             setVisited(used,subset);
             bool flag = canPartition(nums,used,target,partitionLeft - 1);
             resetVisited(used,subset);
             if(flag == true) {
                 return true;
             }
        }
        return false;
    }
    
    vector<vector<int>> findSubSets(vector<int>& nums, 
                                    vector<bool>& used, 
                                    int startIndex, int target) {
        vector<vector<int>> result;
        if(target == 0) {
            result.push_back(vector<int>());
            return result;
        }
        
         
         for(int index = startIndex; index < nums.size(); index++ ) {
             if(used[index] == true || target < nums[index] ) {
                 continue;
             }
            
             used[index] = true;
             
             vector<vector<int>> nextRet = findSubSets(nums,used,
                                                       index+1, 
                                                       target - nums[index]);
             if(nextRet.size() > 0) {
                 for( int i = 0; i < nextRet.size(); i++) {
                      vector<int> curBuffer;
                      curBuffer.push_back(index);
                      for(int j = 0; j < nextRet[i].size();j++) {
                          curBuffer.push_back(nextRet[i][j]);
                      }
                      result.push_back(vector<int>(curBuffer));
                      
                 }
             }
             
             used[index] = false;
         }
        
         return result;
    }
    
    void setVisited(vector<bool>& used, vector<int>& indices) {
        for( int i = 0; i < indices.size(); i++ ) {
            int index = indices[i];
            used[index] = true;
        }
    }
    
    void resetVisited(vector<bool>& used, vector<int>& indices) {
        for( int i = 0; i < indices.size(); i++ ) {
            int index = indices[i];
            used[index] = false;
        }
    }
};