class Solution {
private:
    int gcd(int a,int b) {
        if(a==0) {
            return b;
        }
        if(b==0) {
            return a;
        }
        if(a==b) {
            return a;
        }
        if(a>b) {
            return gcd(a-b,b);
        }
        return gcd(a,b-a);
    }
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<string,int> ratioFreq;
        for(int i=0;i<rectangles.size();i++) {
            vector<int> rectangle = rectangles[i];
            int divisor = gcd(rectangle[0],rectangle[1]);
            int width = rectangle[0]/divisor;
            int height = rectangle[1]/divisor;
            string key = to_string(width)+":"+to_string(height);
            if(ratioFreq.find(key) == ratioFreq.end()) {
                ratioFreq[key] = 0;
            }
            ratioFreq[key]++;
        }
        long long result = 0;
        for(auto entry:ratioFreq) {
            int freq = entry.second;
            result += (long long)(freq)*(freq-1)/2;
        }
        return result;
    }
};