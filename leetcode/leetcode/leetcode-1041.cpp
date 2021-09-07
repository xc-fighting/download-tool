class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direction[4][2] = {
            {0,1}, //north
            {0,-1}, //south
            {-1,0}, //west
            {1,0}   //east
        };
        int transition[4][2] = {
            //direction index from 0->3
            //transition[i] L is transition[i][0]
            // transition[i] R is transition[i][1]
            {2,3},
            {3,2},
            {1,0},
            {0,1}
        };
        int x = 0;
        int y = 0;
        int dir = 0;
        for(int i=0;i<instructions.size();i++)
        {
            if(instructions[i]=='L')
            {
                dir = transition[dir][0];
            }
            else if(instructions[i]=='R')
            {
                dir = transition[dir][1];
            }
            else
            {
                x = x + direction[dir][0];
                y = y + direction[dir][1];
            }
        }
        //if face not to north, must be in circle
        if(dir != 0)
        {
            return true;
        }
        if(dir == 0 && x == 0 && y == 0)
        {
            //if north and back to origin, must be in circle
            return true;
        }
        //if face north and not in origin no circle
        return false;
    }
};
