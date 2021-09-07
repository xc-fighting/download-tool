class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        //sort the array
        sort(S.begin(),S.end());
        int len = S.size();
        int result = 0;
        for(int i = 0;i<S.size();i++)
        {
            for(int j=i+1;j<S.size();j++)
            {
                int target = S[i] + S[j];
                int left = j+1;
                int right = len - 1;
                //find the last element  < target
                while(left+1<right)
                {
                    int mid = left + (right-left)/2;
                    if(S[mid] == target)
                    {
                        right = mid;
                    }
                    else if(S[mid] > target)
                    {
                        right = mid;
                    }
                    else
                    {
                        left = mid;
                    }
                }
                if(S[right] < target)
                {
                    result = result + (right-j);
                }
                else if(S[left]<target)
                {
                    result += left - j;
                }
            }
        }
        return result;
    }
};