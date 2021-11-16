class Solution {
public:
    /**
     * @param graph: the graph
     * @return: the shortest path for all nodes
     */
    int shortestPathLength(vector<vector<int>> &graph) {
        // Write your code here.
        // how to represent state
        // use the pair<string,int> which means current state and current node
        // visited means current state + currentNode as the state key
        int len = graph.size();
        string initialState = "";
        string finalState = "";
        for( int index = 0; index < len; index++ ) {
            initialState += "0";
            finalState += "1";
        }
        queue<pair<string,int>> stateQueue;
        unordered_map<string,int> stateDistance;
        stateDistance[initialState] = 0;
        for( int index = 0; index < len; index++ ) {
               string str = initialState;
               str[index] = '1';
               
               pair<string,int> startState(str,index);
               str = str + ":" + to_string(index);
               stateDistance[str] = 0;
               stateQueue.push(startState);
        }
       
        while( stateQueue.empty() == false ) {
            pair<string,int> frontState = stateQueue.front();
            stateQueue.pop();
            string curState = frontState.first;
            cout<<curState<<","<<frontState.second<<endl;
            int curNode = frontState.second;
            string oldkey = curState + ":" + to_string(curNode);
            cout<<oldkey<<endl;
            for( int index = 0; index < graph[curNode].size(); index++ ) {

                int neighbor = graph[curNode][index];

                string nextState = curState;

                nextState[neighbor] = '1';
                string key = nextState + ":" + to_string(neighbor);
                //cout<<"expand state:"<<nextState<<endl;
                if( stateDistance.find(key) == stateDistance.end() ) {

                    stateDistance[key] = stateDistance[oldkey] + 1;
                  //  cout<<"key:"<<key<<" and distance:"<<stateDistance[key]<<endl;
                    stateQueue.push(pair<string,int>(nextState,neighbor));

                }
                else {
                    if( (1 + stateDistance[oldkey]) < stateDistance[key]) {
                       
                        stateDistance[key] = 1 + stateDistance[oldkey];
                        //cout<<key<<" "<<stateDistance[key]<<endl;
                        stateQueue.push(pair<string,int>(nextState,neighbor));
                    }
                }
            }


        }
        int shortest = INT_MAX;
        for( int index = 0; index < len; index++ ) {
            string candidateKey = finalState + ":" + to_string(index);
            if( stateDistance.find(candidateKey) != stateDistance.end() ) {
                shortest = min(shortest, stateDistance[candidateKey]);
            }
        }
        if( shortest == INT_MAX ) {
            return -1;
        }
        return shortest;

    }
};