class Solution {
public:
    //this is most fucking important function
    vector<int> convertToPos(int n, int input)
    {
        int rowsFromBottom = input / n;
        int actualRow = rowsFromBottom;
        if(input % n != 0)
        {
            actualRow += 1;
        }
        vector<int> result(2,0);
        result[0] = n - actualRow;
        if(actualRow % 2 ==0)
        {
            //from right to left
            int remain = input - n*(actualRow - 1);
            result[1] = n - remain;
        }
        else
        {
            //from left to right
            int remain = input - n*(actualRow-1);
            result[1] = remain - 1;
        }
        return result;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        
        queue<pair<int,int>> distanceQueue;
        map<int,int> distanceMap;
        int n = board.size();
        distanceQueue.push(pair<int,int>(1,0));
        distanceMap[1] = 0;
        int step = 0;
        while(distanceQueue.empty()==false)
        {
            
                 pair<int,int> topElem = distanceQueue.front();
                 distanceQueue.pop();
                 for(int forward = 1;forward <= 6 ; forward++)
                 {
                    int newElem = min(topElem.first + forward,n*n);
                    
                    
                    vector<int> newpos = convertToPos(n,newElem);
                    if(board[newpos[0]][newpos[1]]==-1)
                    {
                        if(distanceMap.find(newElem)==distanceMap.end())
                        {
                            distanceMap[newElem] = topElem.second + 1;
                            distanceQueue.push(pair<int,int>(newElem,distanceMap[newElem]));
                        }
                        else
                        {
                           if(topElem.second+1 < distanceMap[newElem])
                           {
                               distanceMap[newElem] = topElem.second + 1;
                               distanceQueue.push(pair<int,int>(newElem,distanceMap[newElem]));
                           }
                           
                        }
                        
                        
                    }
                    else
                    {
                        //ladder or snake
                        int ladderdst = board[newpos[0]][newpos[1]];
                        if(distanceMap.find(ladderdst)==distanceMap.end())
                        {
                            distanceMap[ladderdst] = topElem.second + 1;
                            distanceQueue.push(pair<int,int>(ladderdst,distanceMap[ladderdst]));
                        }
                        else
                        {
                            if(topElem.second+1 < distanceMap[ladderdst])
                            {
                                distanceMap[ladderdst] = topElem.second + 1;
                                distanceQueue.push(pair<int,int>(ladderdst,distanceMap[ladderdst]));
                            }
                        }
                        
                    }
                     
               }
           
           
        }
        if(distanceMap.find(n*n)==distanceMap.end())
        {
            return -1;
        }
        return distanceMap[n*n];
        
        
    }
};
