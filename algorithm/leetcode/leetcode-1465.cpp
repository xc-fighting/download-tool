class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        vector<int> newVertical;
        vector<int> newHorizontal;
        int lenh = horizontalCuts.size();
        int lenv = verticalCuts.size();
        for(int i=0;i<verticalCuts.size();i++)
        {
            if(i==0)
            {
                newVertical.push_back(verticalCuts[i]);
                continue;
            }
           
            newVertical.push_back(verticalCuts[i]-verticalCuts[i-1]);
            
        }
        newVertical.push_back(w-verticalCuts[lenv-1]);
        for(int i=0;i<horizontalCuts.size();i++)
        {
            if(i==0)
            {
                newHorizontal.push_back(horizontalCuts[i]);
                continue;
            }
            
            newHorizontal.push_back(horizontalCuts[i]-horizontalCuts[i-1]);
            
        }
        newHorizontal.push_back(h-horizontalCuts[lenh-1]);
        int result = 0;
        for(int i=0;i<newVertical.size();i++)
        {
            // cout<<"the vertical:"<<newVertical[i]<<endl;
             for(int j=0;j<newHorizontal.size();j++)
             {
                //  cout<<"the horizontal:"<<newHorizontal[j]<<endl;
                  int temp = newVertical[i]*newHorizontal[j];
                  if(temp>result)
                  {
                      result = temp;
                  }
             }
        }
        return result;
    }
};