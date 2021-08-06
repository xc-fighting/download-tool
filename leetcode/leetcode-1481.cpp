class Solution {
public:
    static bool compare(pair<int,int> left,pair<int,int> right)
    {
        if(left.second < right.second)
        {
            return true;
        }
        return false;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> num_freq;
     //   cout<<"start"<<endl;
        for(int i=0;i<arr.size();i++)
        {
            if(num_freq.find(arr[i])==num_freq.end())
            {
                num_freq[arr[i]] = 0;
            }
            num_freq[arr[i]]++;
        }
    //    cout<<"here"<<endl;
        vector<pair<int,int>> numlist;
        for(auto itr = num_freq.begin();itr!=num_freq.end();itr++)
        {
            numlist.push_back(pair<int,int>(itr->first,itr->second));
        }
   //      for(int i=0;i<numlist.size();i++)
    //    {
    //        cout<<numlist[i].first<<endl;
   //     } 
      //  cout<<"finish push"<<endl;
        sort(numlist.begin(),numlist.end(),compare);
       // cout<<"maybe"<<endl;
       
        int curIndex = 0;
        int opLeft = k;
        while(opLeft>0 && curIndex < numlist.size())
        {
            while( curIndex < numlist.size() )
            {
                if(opLeft>=numlist[curIndex].second)
                {
                    opLeft = opLeft - numlist[curIndex].second;
                    curIndex++;
                }
                else
                {
                    opLeft -= numlist[curIndex].second;
                    break;
                }
                 
            }
          
        }
       // cout<<"size:"<<curIndex<<endl;
        return numlist.size()-curIndex;
    }
};