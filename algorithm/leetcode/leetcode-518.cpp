class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int types = coins.size();
        vector<vector<int>> memo(amount+1,vector<int>(types,-1));
        return getWays(memo,amount,coins,0);
    }
    
    int getWays(vector<vector<int>>& memo,int amount,vector<int>& coins, int currentType)
    {
         if(amount<0)
         {
             return 0;
         }
         if(amount==0)
         {
             return 1;
         }
         if(currentType == coins.size() && amount > 0)
         {
             return 0;
         }
         if(memo[amount][currentType]!=-1)
         {
              return memo[amount][currentType];
         }
         int ways = 0;
         int moneyValue = coins[currentType];
         int numCoins = amount/moneyValue;
         for(int choose = 0; choose <= numCoins; choose++)
         {
             int currentAmount = choose * moneyValue;
             int currentWays = getWays(memo,amount-currentAmount,coins,currentType+1);
             ways += currentWays;
         }
         memo[amount][currentType] = ways;
         return ways;
    }
};



class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /* use dynamic programming
           memo[amount][types] represent number of ways to get amount
           use types different kinds of coins
           for base condition memo[0][j] = 1
              memo[i][0] = 0 for i >0
           formula:
              memo[i][j] = memo[amount][types-1] + memo[amount-coins[types-1]][types]
         */
         if(amount==0)
         {
             return 1;
         }
         if(coins.size()==1)
         {
             if(amount % coins[0] == 0)
             {
                 return 1;
             }
             return 0;
         }
         sort(coins.begin(),coins.end());
         int len = coins.size();
         vector<vector<int>> memo(amount+1,vector<int>(len+1,-1));
         memo[0][0] = 1;
         for(int i=1;i<=len;i++)
         {
             memo[0][i] = 1;
         }
         for(int i=1;i<=amount;i++)
         {
             memo[i][0] = 0;
         }
         for(int value = 1;value<=amount;value++)
         {
             for(int types=1;types<=len;types++)
             { 
                 //cout<<value<<" "<<types<<endl;
                 int moneyVal = coins[types-1];
                 if(value>=moneyVal)
                 { 
                    memo[value][types]=memo[value][types-1] +  memo[value-moneyVal][types]; 
                 }
                 else
                 {
                     memo[value][types] = memo[value][types-1];
                 }
                 
                 
             }
         }
         return memo[amount][len];
    }
    
   
};