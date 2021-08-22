class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int writeHead = m + n -1;
        int index1 = m -1;
        int index2 = n -1;
        while(index1 >= 0 && index2 >= 0)
        {
            if(nums1[index1] >= nums2[index2])
            {
                nums1[writeHead]=nums1[index1];
                index1--;
            }
            else
            {
                nums1[writeHead] = nums2[index2];
                index2--;
            }
            writeHead--;
        }
        if(index1==0 && index2 == 0)
        {
            return;
        }
        while(index2 >= 0)
        {
            nums1[writeHead] = nums2[index2];
            index2--;
            writeHead--;
        }
        return;
    }
};