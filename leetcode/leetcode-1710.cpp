class Solution {
public:
    static bool compare(vector<int> left,vector<int> right)
    {
        if(left[1]<right[1])
        {
            return false;
            //swap other
        }
        return true;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),compare);
    
        int units = 0;
        int truckLeft = truckSize;
        for(int i=0;i<boxTypes.size();i++)
        {
            if(truckLeft <= 0)
            {
                break;
            }
            
            int num = boxTypes[i][0];
            int unitPer = boxTypes[i][1];
            if(truckLeft >= num)
            {
                truckLeft = truckLeft - num;
                units += num*unitPer;
            }
            else
            {
                
                units += truckLeft*unitPer;
                truckLeft = 0;
            }
            
        }
        return units;
    }
};