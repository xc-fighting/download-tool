class Solution {
private:
   vector<string> split(string input, string splitter)
   {
       string str = input + splitter;
       int pose = str.find(splitter);
       vector<string> result;
       while( pose != string::npos )
       {
           string component = str.substr(0,pose);
           result.push_back(component);
           pose = pose + splitter.size();
           str = str.substr(pose);
           pose = str.find(splitter);
       }
       return result;
   }

   string serialize(vector<vector<int>>& board)
   {
      string firstrow = to_string(board[0][0]) + " " + to_string(board[0][1]) + " " + to_string(board[0][2]);
      string secondrow = to_string(board[1][0]) + " " + to_string(board[1][1]) + " " + to_string(board[1][2]);
      return firstrow + ":" + secondrow;
   }

   vector<vector<int>> deserialize(string& input)
   {
       vector<string> rows = split(input,":");
       vector<vector<int>> result(2,vector<int>(3,0));
       vector<string> first_row = split(rows[0]," ");
       vector<string> second_row = split(rows[1]," ");
       result[0][0] = stoi(first_row[0]);
       result[0][1] = stoi(first_row[1]);
       result[0][2] = stoi(first_row[2]);
       result[1][0] = stoi(second_row[0]);
       result[1][1] = stoi(second_row[1]);
       result[1][2] = stoi(second_row[2]);
       return result;
   }
public:
    /**
     * @param board: the given board
     * @return:  the least number of moves required so that the state of the board is solved
     */
    int slidingPuzzle(vector<vector<int>> &board) {
        // write your code here
        string finalState = "1 2 3:4 5 0";
        int step = 0;
        queue<string> stateQueue;
        unordered_set<string> seen;
        string currentState = serialize(board);
        stateQueue.push(currentState);
        seen.insert(currentState);
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        while(stateQueue.empty()==false)
        {
            int size = stateQueue.size();
            for(int i=0;i<size;i++)
            {
                string serializeStr = stateQueue.front();
                stateQueue.pop();
                if(serializeStr.compare(finalState) == 0)
                {
                    return step;
                }
                vector<vector<int>> currentBoard = deserialize(serializeStr);
                int zeroRow = -1;
                int zeroCol = -1;
                for(int row = 0; row < 2; row++ )
                {
                   for(int col = 0; col < 3; col++ )
                   {
                       if( currentBoard[row][col] == 0 )
                       {
                           zeroRow = row;
                           zeroCol = col;
                       }
                   }
                }
             //   cout<<zeroRow <<" "<<zeroCol<<endl;
                for(int index = 0; index < 4; index++ )
                {
                    int neighborRow = zeroRow + dx[index];
                    int neighborCol = zeroCol + dy[index];
                    if(neighborRow < 0 || neighborRow >= 2 
                       || neighborCol < 0 || neighborCol >= 3 )
                    {
                        continue;
                    }
                    else
                    {
                        //swap
                        int temp = currentBoard[neighborRow][neighborCol];
                        currentBoard[zeroRow][zeroCol] = temp;
                        currentBoard[neighborRow][neighborCol] = 0;
                        string neighbor_str = serialize(currentBoard);
                        if(seen.find(neighbor_str) == seen.end())
                        {
                            seen.insert(neighbor_str);
                            stateQueue.push(neighbor_str);
                        }
                        currentBoard[neighborRow][neighborCol] = temp;
                        currentBoard[zeroRow][zeroCol] = 0;
                    }
                }

            }
            step++;
        }
        return -1;
    }
};