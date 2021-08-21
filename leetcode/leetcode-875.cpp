class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(piles.size() > h)
        {
            return -1;
        }
        int sum = 0;
        int maxK = INT_MIN;
        for(int i=0;i<piles.size();i++)
        {
          //  sum += piles[i];
            maxK = max(maxK,piles[i]);
        }
        int left = 1;
        int right = maxK;
        //find the first 
        while(left<right)
        {
            int mid = left + (right-left)/2;
            bool eatable = canEat(piles,h,mid);
            if(eatable == true)
            {
                right = mid;
            }
            else
            {
                left = mid+ 1;
            }
            
        }
        return left;
    }
    bool canEat(vector<int>& piles,int h,int k)
    {
        int hourToUse = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(k >= piles[i])
            {
                hourToUse++;
            }
            else
            {
                int hour = piles[i] / k;
                if(piles[i] % k !=0)
                {
                    hour++;
                }
                hourToUse += hour;
            }
            if(hourToUse > h)
            {
                return false;
            }
        }
        return true;
    }
};