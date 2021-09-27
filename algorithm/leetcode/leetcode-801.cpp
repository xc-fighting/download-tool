// TLE solution
class Solution {
public:
    void swap(vector<int>& input1,vector<int>& input2, int index) {
        int temp = input1[index];
        input1[index] = input2[index];
        input2[index] = temp;
        return;
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<string,int> memo;
        return getMinSwap( memo, nums1,nums2,0,-1,-1);
    }
    
    int getMinSwap( unordered_map<string,int>& memo, vector<int>& nums1, vector<int>& nums2, int index, int pre1, int pre2 ) {
        if( index == nums1.size() ) {
            return 0;
        }
        string key = to_string(pre1)+":"+to_string(pre2)+"->"+to_string(index);
        if(memo.find(key) != memo.end()) {
            return memo[key];
        }
        int result = INT_MAX;
        if( pre1 < nums1[index] && pre2 < nums2[index] ) {
            //try no swap
            int candidate = getMinSwap( memo, nums1,nums2,index+1, nums1[index], nums2[index]);
            result = min(result, candidate);
            //try swap too
            if( nums2[index] > pre1 && nums1[index] > pre2 ) {
                 swap(nums1,nums2,index);
                 int swapcandidate = getMinSwap( memo, nums1,nums2,index+1, nums1[index], nums2[index]);
                 if( swapcandidate != INT_MAX ) {
                     result = min( result, 1 + swapcandidate );
                 }
                 swap(nums1,nums2,index);
            }
            
        }
        
        if( pre1 >= nums1[index] ) {
            if( pre1 < nums2[index] ) {
                swap(nums1,nums2,index);
                int candidate = getMinSwap( memo, nums1,nums2,index+1, nums1[index],nums2[index]);
                if(candidate != INT_MAX) {
                    result = min( result, 1 + candidate );
                }
                swap(nums1,nums2,index);
            }
            
        }
        
        if( pre2 >= nums2[index] ) {
            if( pre2 < nums1[index] ) {
                swap(nums1,nums2,index);
                int candidate = getMinSwap( memo, nums1,nums2,index+1, nums1[index],nums2[index]);
                if(candidate != INT_MAX) {
                    result = min( result, 1 + candidate );
                }
                swap(nums1,nums2,index);
            }
        }
        memo[key] = result;
        return result;
    }
};