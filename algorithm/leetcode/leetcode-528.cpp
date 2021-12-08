class Solution {
private:
    vector<int> presum;
    int total;
public:
    Solution(vector<int>& w) {
        srand(time(NULL));
        int len = w.size();
        presum = vector<int>(len, 0);
        total = 0;
        for(int idx = 0; idx < len; idx++) {
            total += w[idx];
            presum[idx] = total;
        }
    }
    
    int pickIndex() {
        int weight = rand() % (total);
        int res = -1;
        for(int idx = 0; idx < presum.size(); idx++) {
            if(presum[idx] > weight) {
                res = idx;
                break;
            }
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
