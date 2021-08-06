// tle
class Compare
{
public:
    bool operator()(vector<double>& left,vector<double>& right)
    {
       
        if(left[2] < right[2])
        {
            return true;
        }
        return false;
    }
};
class Solution {
public:
    double getDiff(double pass,double total)
    {
        double new_ratio = (pass+1)/(total+1);
        double ratio = pass/total;
        return new_ratio-ratio;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<vector<double>,vector<vector<double>>,Compare> pq;
        for(int i=0;i<classes.size();i++)
        {
            vector<double> arr(3,0);
            double diff = getDiff(classes[i][0],classes[i][1]);
            arr[0] = classes[i][0];
            arr[1] = classes[i][1];
            arr[2] = diff;
            pq.push(arr);
        }
        int studentsRemain = extraStudents;
        while( studentsRemain > 0 )
        {
            vector<double> maxOnes = pq.top();
          //  cout<<maxOnes[0]<<" "<<maxOnes[1]<<endl;
            pq.pop();
            maxOnes[0]+=1;
            maxOnes[1]+=1;
            double diff = getDiff(maxOnes[0],maxOnes[1]);
            maxOnes[2] = diff;
            pq.push(maxOnes);
            studentsRemain--;
        }
        double totalSum = 0.0;
        while(pq.empty()==false)
        {
            vector<double> current = pq.top();
        //    cout<<current[0]<<" "<<current[1]<<endl;
            totalSum += double(current[0]/current[1]);
            pq.pop();
        }
        int len = classes.size();
        return totalSum/len;
        
    }
};