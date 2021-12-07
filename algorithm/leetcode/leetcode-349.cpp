class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        
        int idx1 = 0;
        int idx2 = 0;
        
        while(idx1 < nums1.size() && idx2 < nums2.size()) {
            if(nums1[idx1] == nums2[idx2]) {
                if(result.size() > 0 && nums1[idx1] == result[result.size()-1]) {
                    idx1++;
                    idx2++;
                    continue;
                }
                else {
                    result.push_back(nums1[idx1]);
                    idx1++;
                    idx2++;
                }
                
            }
            else if(nums1[idx1] < nums2[idx2]) {
                idx1++;
            }
            else {
                idx2++;
            }
        }
        return result;
    }
};
