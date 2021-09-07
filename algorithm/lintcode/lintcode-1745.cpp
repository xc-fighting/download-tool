class Solution {
public:
    /**
     * @param A: a array
     * @return: is it monotonous
     */
    bool isMonotonic(vector<int> &A) {
        // Write your code here.
        bool increase = false;
        int index = 0;
        int len = A.size();
        while( index < len - 1 && A[index] == A[index+1])
        {
            index++;
        }
        if(index == len -1 )
        {
            return true;
        }
        if(A[index] < A[index+1])
        {
            increase = true;
        }
        else
        {
            increase = false;
        }
        int start = index;
        while(start < len-1)
        {
            if(increase)
            {
               if( A[start] > A[start+1] )
               {
                   return false;
               }
            }
            else
            {
               if( A[start] < A[start+1] )
               {
                   return false;
               }
            }
            start++;
        }
        return true;
    }
};