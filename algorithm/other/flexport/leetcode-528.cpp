class Solution {
private:
    vector<int> presum;
    int total;
public:
    Solution(vector<int>& w) {
        int len = w.size();
        presum = vector<int>(len, 0);
        presum[0] = w[0];
        for(int idx = 1; idx < len; idx++) {
            presum[idx] = presum[idx-1] + w[idx];
        }
        this->total = presum[len-1];
        srand(time(NULL));
    }
    
    int pickIndex() {
        int weight = rand() % total;
        int pick = -1;
        //logic below: find the first index which is larger than weight
        /*
        for(int idx = 0; idx < presum.size(); idx++) {
            if(presum[idx] <= weight) {
                continue;
            }
            else {
                pick = idx;
                break;
            }
        }*/
        
        int left = 0;
        int right = presum.size() - 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            if(presum[mid] <= weight) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        if(presum[left] > weight) {
           return left;
        }
        if(presum[right] > weight) {
            return right;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */