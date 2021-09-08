// TLE solution
class Solution {
public:
    /**
     * @param nums: the gievn integers
     * @return: the total Hamming distance between all pairs of the given numbers
     */
    int getDistance(int input1,int input2)
    {
        int mask = input1 ^ input2;
        int distance = 0;
        while(mask > 0)
        {
           int flag = mask & 1;
           if(flag >0)
           {
               distance++;
           }
           mask = mask >> 1;
        }
        return distance;
    }
    int totalHammingDistance(vector<int> &nums) {
        // Write your code here
        int result = 0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int distance = getDistance(nums[i],nums[j]);
                result += distance;
            }
        }
        return result;
    }
};

//solution:
class Solution {
public:
    /**
     * @param nums: the gievn integers
     * @return: the total Hamming distance between all pairs of the given numbers
     */
    
    int totalHammingDistance(vector<int> &nums) {
        int result = 0;
        int len = nums.size();
        for( int move = 0; move < 32; move++ )
        {
            int bitcount = 0;
            for( int i = 0; i < nums.size(); i++ )
            {
                int number = nums[i];
                int mask = ( number >> move ) & 1;
                if( mask != 0 )
                {
                    bitcount++;
                }
            }
            result += bitcount*(len-bitcount);
        }
        return result;
    }
};