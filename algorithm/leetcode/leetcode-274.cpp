class Solution {
public:
    int getCount(vector<int>& citations, int k) {
        int count = 0;
        for(int idx = 0; idx < citations.size(); idx++) {
            if(citations[idx] >= k) {
                count++;
            }
        }
        return count;
    }
    int hIndex(vector<int>& citations) {
        //binary search on result
        int leftH = 1;
        int rightH = citations.size();
        while(leftH + 1 < rightH) {
            int midH = leftH + (rightH - leftH) / 2;
            int actualCount = getCount(citations, midH);
            if(actualCount == midH) {
                leftH = midH;
            }
            else if(actualCount < midH) {
                rightH = midH;
            }
            else{
                leftH = midH;
            }
        }
        
        if(getCount(citations, rightH) >= rightH) {
            return rightH;
        }
        
        if(getCount(citations, leftH) >= leftH) {
            return leftH;
        }
        
        
        
        //cout<<"impossible"<<endl;
        return 0;
    }
};
