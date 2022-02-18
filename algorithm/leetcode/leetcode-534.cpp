//brute force:
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       
       int count = 0;
        //O(nlogn)
       sort(nums.begin(), nums.end());
       for(int idx = 0; idx < nums.size(); idx++) {
           if(idx > 0 && nums[idx] == nums[idx-1]) {
               continue;
           }
           int cur = nums[idx];
           int larger = cur + k;
           for(int next = idx + 1; next < nums.size(); next++) {
               if(nums[next] == larger) {
                   count++;
                   break;
               }
           }
       }
    
       return count;
    }
};

//two pointer:



//hash map
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
       
       map<int, int> numFreq;
       for(int idx = 0; idx < nums.size(); idx++) {
           
           int cur = nums[idx];
           if(numFreq.find(cur) == numFreq.end()) {
               numFreq[cur] = 0;
           }
           numFreq[cur]++;
       }
       
       int count = 0;
       for(auto entry: numFreq) {
           int val = entry.first;
           int freq = entry.second;
         //  cout<<val<<" "<<freq<<endl;
           int less = val - k;
           if(less == val && numFreq[val] > 1) {
                
                count++;
                
           }
           
           else if(less != val && numFreq.find(less) != numFreq.end()) {
              // cout<<"why:"<<val<<","<<less<<endl;
               count++;
           }
           
       }
       
       return count;
    }
};