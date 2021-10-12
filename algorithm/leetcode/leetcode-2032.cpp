class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        vector<int> result;
        for( int value = 1; value <= 100; value++ ) {
            int appearFreq = 0;
            if( search(nums1,value) ) {
                appearFreq++;
            }
            
            if( search(nums2,value) ) {
                appearFreq++;
            }
            
            if( search(nums3,value) ) {
                appearFreq++;
            }
            
            if( appearFreq >= 2 ) {
                result.push_back(value);
            }
        }
        return result;
    }
    
    bool search(vector<int>& input, int target) {
        int left = 0;
        int right = input.size() - 1;
        while( left <= right ) {
            int mid = left + ( right - left ) / 2;
            if( input[mid] == target ) {
                return true;
            }
            else if( input[mid] < target ) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return false;
    }
};


class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
       vector<vector<int>> countMap(3,vector<int>(101,0));
       for( int index = 0; index < nums1.size(); index++ ) {
           countMap[0][nums1[index]]++;
       }
        
       for( int index = 0; index < nums2.size(); index++ ) {
           countMap[1][nums2[index]]++;
       }
        
       for( int index = 0; index < nums3.size(); index++ ) {
           countMap[2][nums3[index]]++;
       }
        
       vector<int> result;
       for( int num = 1; num <= 100; num++ ) {
           int count = 0;
           
           if(countMap[0][num] > 0) {
               count++;
           }
           
           if(countMap[1][num] > 0) {
               count++;
           }
           
           if(countMap[2][num] > 0 ) {
               count++;
           }
           
           if( count >= 2 ) {
               result.push_back(num);
           }
       }
        
       return result;
    }
    
   
};
