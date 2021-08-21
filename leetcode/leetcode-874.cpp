class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> direction(2,0);
        direction[0] = 0;
        direction[1] = 1;
        vector<int> pos(2,0);
        set<string> stopPos;
        for(int i=0;i<obstacles.size();i++)
        {
            stopPos.insert(toString(obstacles[i]));
        }
        int maxDis = 0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-2)
            {
                turnLeft(direction,90);
            }
            else if(commands[i]==-1)
            {
                turnRight(direction,90);
            }
            else
            {
                int step = 1;
              //  bool valid = true;
                while(step <= commands[i])
                {
                    forward(pos,direction,1);
                    if(stopPos.find(toString(pos)) != stopPos.end())
                    {
                        //valid = false;
                        pos[0] = pos[0] - direction[0];
                        pos[1] = pos[1] - direction[1];
                        break;
                    }
                    step++;
                }
               // if(valid)
                //{
                    int dis = distance(pos);
                    maxDis = max(maxDis, dis);
                //}
            }
        }
        return maxDis;
    }
    
    int distance(vector<int>& pos)
    {
        return pos[0]*pos[0] + pos[1]*pos[1];
    }
    
    string toString(vector<int>& pos)
    {
        return to_string(pos[0])+":"+to_string(pos[1]);
    }
    
    void turnLeft(vector<int>& direction, int theta)
    {
        /*
           direction vector should be normalized
           which means (cos(alpha),sin(alpha))
           after turn left for a theta
           new direction:
            cos(alpha+theta),sin(alpha+theta)
            => cos(alpha)*cos(theta) - sin(alpha)*sin(theta)
               sin(alpha)*cos(theta) + cos(alpha)* sin(theta)
               
             for this cos(90) = 0 sin(90) = 1
             new direction:
               dy = direction[0]*1 + 0*direction[1]
               dx = direction[0]*0 - 1*direction[1]
        */
        
         int dx = -direction[1];
         int dy = direction[0];
         direction[0] = dx;
         direction[1] = dy;
         return;
    }
    
    void turnRight(vector<int>& direction, int theta)
    {
        /*
           same thing here
           cos(alpha-theta),sin(alpha-theta)
            => cos(alpha)*cos(theta) + sin(alpha)*sin(theta)
               sin(alpha)*cos(theta) - cos(alpha)* sin(theta)
            
            new direction:
              dx =  direction[1]
              dy =  -direction[0]
        */
         int dx = direction[1];
         int dy = -direction[0];
         direction[0] = dx;
         direction[1] = dy;
    }
    
    void forward(vector<int>& pos,vector<int>& direction,int step)
    {
        pos[0] = pos[0] + direction[0] * step;
        pos[1] = pos[1] + direction[1] * step;
        return;
    }
};