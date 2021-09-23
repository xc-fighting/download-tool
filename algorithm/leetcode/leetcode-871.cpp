//Memory out of range
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // postion i with fuel amount
        // choose where I can reach, with fuel amount
        // find from stations
        // for any given station, fuel it/not
        if(stations.size()==0) {
            if(startFuel >= target) {
                return 0;
            }
            return -1;
        }
        int StationNum = stations.size();
        long totalFuel = 0;
        for(int i = 0; i< stations.size(); i++) {
            totalFuel += stations[i][1];
        }
        totalFuel += startFuel;
        vector<vector<vector<long>>> memo(StationNum, vector<vector<long>>(target+1,vector<long>(totalFuel+1,-1)));
        long initialFuel = startFuel;
        int result = getMinStop(memo,target,initialFuel,stations,0,0);
        if(result == INT_MAX) {
            return -1;
        }
        return result;
        
    }
    
    int getMinStop(vector<vector<vector<long>>>& memo,int target, long currentFuel, vector<vector<int>>& stations, int curStation,int curPos) {
        if(curPos + currentFuel >= target) {
            return 0;
        }
        if(curStation == stations.size()) {
            return INT_MAX;
        }
       // cout<<"get here"<<endl;
       // cout<<curPos<<" "<<curStation<<" "<<currentFuel<<endl;
        if(memo[curStation][curPos][currentFuel] != -1) {
            return memo[curStation][curPos][currentFuel];
        }
        int longestDistanceDrive = curPos + currentFuel;
     //   cout<<"the longest DistanceDrive:"<<longestDistanceDrive<<endl;
        //search in the stations, find the last one which is <= longestDistanceDrive
        //then choose to arrive 
        int left = curStation;
        int right = stations.size()-1;
        while(left + 1 < right) {
            int mid = left + (right-left)/2;
            int midPos = stations[mid][0];
            if(midPos <= longestDistanceDrive) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        int finalIndex = -1;
        if(stations[right][0] <= longestDistanceDrive) {
            finalIndex = right;
        }
        else if(stations[left][0] <= longestDistanceDrive) {
            finalIndex = left;
        }
        if(finalIndex == -1) {
            return INT_MAX;
        }
     //   cout<<"the final index:"<<finalIndex<<endl;
        //range from curPos -> finalIndex
        int stops = INT_MAX;
        for(int i = curStation; i<=finalIndex; i++) {
            int fuelUse = stations[i][0] - curPos;
            //refuel there
            int choice1 = getMinStop(memo,target,currentFuel-fuelUse+stations[i][1], stations,i+1, stations[i][0]);
            if(choice1 != INT_MAX) {
                stops = min(stops,choice1+1);
            }
            
            int choice2 = getMinStop(memo,target,currentFuel-fuelUse,stations,i+1, stations[i][0]);
            if(choice2 != INT_MAX) {
                stops = min(stops,choice2);
            }
            
        }
        memo[curStation][curPos][currentFuel] = stops;
        return stops;
    }
};

//TLE:
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // postion i with fuel amount
        // choose where I can reach, with fuel amount
        // find from stations
        // for any given station, fuel it/not
        if(stations.size()==0) {
            if(startFuel >= target) {
                return 0;
            }
            return -1;
        }
        int result = getMinStop(target,startFuel,stations,0,0);
        if(result == INT_MAX) {
            return -1;
        }
        return result;
        
    }
    
    int getMinStop(int target, int currentFuel, vector<vector<int>>& stations, int curStation,int curPos) {
        if(curPos + currentFuel >= target) {
            return 0;
        }
        
        int longestDistanceDrive = curPos + currentFuel;
     //   cout<<"the longest DistanceDrive:"<<longestDistanceDrive<<endl;
        //search in the stations, find the last one which is <= longestDistanceDrive
        //then choose to arrive 
        int left = curStation;
        int right = stations.size()-1;
        while(left + 1 < right) {
            int mid = left + (right-left)/2;
            int midPos = stations[mid][0];
            if(midPos <= longestDistanceDrive) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
        int finalIndex = -1;
        if(stations[right][0] <= longestDistanceDrive) {
            finalIndex = right;
        }
        else if(stations[left][0] <= longestDistanceDrive) {
            finalIndex = left;
        }
        if(finalIndex == -1) {
            return INT_MAX;
        }
     //   cout<<"the final index:"<<finalIndex<<endl;
        //range from curPos -> finalIndex
        int stops = INT_MAX;
        for(int i = curStation; i<=finalIndex; i++) {
            int fuelUse = stations[i][0] - curPos;
            //refuel there
            int choice1 = getMinStop(target,currentFuel-fuelUse+stations[i][1], stations,i+1, stations[i][0]);
            if(choice1 != INT_MAX) {
                stops = min(stops,choice1+1);
            }
            
            int choice2 = getMinStop(target,currentFuel-fuelUse,stations,i+1, stations[i][0]);
            if(choice2 != INT_MAX) {
                stops = min(stops,choice2);
            }
            
        }
        
        return stops;
    }
};