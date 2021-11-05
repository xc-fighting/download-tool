class SparseVector {
private:
    
    
    
public:
    unordered_map<int,int> posValue;
    
    SparseVector(vector<int> &nums) {
        
        for( int index = 0; index < nums.size(); index++ ) {
            
            if( nums[index] == 0 ) {
                continue;
            }
            posValue[index] = nums[index];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for( auto posValPair: posValue ) {
            
            int pos = posValPair.first;
            int val = posValPair.second;
            if( vec.posValue.find(pos) != vec.posValue.end() ) {
                 result += val * vec.posValue[pos];
            }
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);