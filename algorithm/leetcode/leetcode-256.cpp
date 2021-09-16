class Solution {

public:
    int minCost(vector<vector<int>>& costs) {
        
        int size = costs.size();
        vector<vector<int>> memo = vector<vector<int>>(3,vector<int>(size,-1));
        return traverse(costs,memo,-1,0);
        
    }
    
    int traverse(vector<vector<int>>& costs,vector<vector<int>>& memo,int colorSelection,int curHouse) {
        if(curHouse == costs.size()) {
            return 0;
        }
        if(colorSelection==-1) {
            //choose 0,1,2
            int selection0 = costs[curHouse][0]
                + min(traverse(costs,memo,1,curHouse+1),traverse(costs,memo,2,curHouse+1));
            int selection1 = costs[curHouse][1]+
                      min(traverse(costs,memo,0,curHouse+1),traverse(costs,memo,2,curHouse+1));
            int selection2 = costs[curHouse][2] +
                          min(traverse(costs,memo,0,curHouse+1),traverse(costs,memo,1,curHouse+1));
            return min(selection0,min(selection1,selection2));
            
        }
        
        if(memo[colorSelection][curHouse] != -1) {
            return memo[colorSelection][curHouse];
        }
        int result = -1;
        if(colorSelection == 0) {
            int curCost = costs[curHouse][0];
            int choice1 = traverse(costs,memo,1,curHouse+1);
            int choice2 = traverse(costs,memo,2,curHouse+1);
            result = min(choice1,choice2) + curCost;
        }
        else if(colorSelection == 1) {
            int curCost = costs[curHouse][1];
            int choice1 = traverse(costs,memo,0,curHouse+1);
            int choice2 = traverse(costs,memo,2,curHouse+1);
            result = min(choice1,choice2) + curCost;
        }
        else {
            int curCost = costs[curHouse][2];
            int choice1 = traverse(costs,memo,1,curHouse+1);
            int choice2 = traverse(costs,memo,0,curHouse+1);
            result = min(choice1,choice2) + curCost;
        }
        memo[colorSelection][curHouse] = result;
        return result;
    }
};


class Solution {

public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> memo(3,vector<int>(n,-1));
        memo[0][n-1] = costs[n-1][0];
        memo[1][n-1] = costs[n-1][1];
        memo[2][n-1] = costs[n-1][2];
        for(int i=n-2;i>=0;i--) {
            //choose 0
            memo[0][i] = costs[i][0] + min(memo[1][i+1],memo[2][i+1]);
            //choose 1
            memo[1][i] = costs[i][1] + min(memo[0][i+1],memo[2][i+1]);
            //choose 2
            memo[2][i] = costs[i][2] + min(memo[0][i+1],memo[1][i+1]);
        }
        
        return min(memo[0][0],min(memo[1][0],memo[2][0]));
        
    }
    
   
};