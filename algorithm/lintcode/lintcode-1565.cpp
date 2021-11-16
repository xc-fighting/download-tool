class Solution {
public:
    /**
     * @param length: the length of board
     * @param connections: the connections of the positions
     * @return: the minimum steps to reach the end
     */
    vector<int> expand(unordered_map<int,vector<int>>& graph,unordered_set<int>& seen, int pos ) {
        queue<int> state;
        state.push(pos);
        vector<int> result;
        seen.insert(pos);
        while( state.empty() == false ) {
            int front = state.front();
            state.pop();
            result.push_back(front);
            for( int neighbor: graph[front] ) {
                if( seen.find( neighbor ) == seen.end() ) {
                    seen.insert(neighbor);
                    state.push(neighbor);
                }
            }
        }
        return result;

    }
    int modernLudo(int length, vector<vector<int>> &connections) {
        // Write your code here
        unordered_map<int,vector<int>> graph;
        for( int index = 0; index < connections.size(); index++ ) {
            vector<int> connection = connections[index];
            if( graph.find(connection[0]) == graph.end() ) {
                graph[connection[0]] = vector<int>();
            }
            graph[connection[0]].push_back(connection[1]);
        }

        //get the minimum path from position 1 to length
        unordered_set<int> seen;
        queue<int> stateQueue;
        stateQueue.push(1);
        seen.insert(1);
        int step = 0;
        while( stateQueue.empty() == false ) {
            int size = stateQueue.size();
            for(int index = 0; index < size; index++) {
                 int front = stateQueue.front();
                 stateQueue.pop();
                 if( front == length ) {
                     return step;
                 }
                 for( int dice = 1; dice <= 6; dice++ ) {
                     int newPos = front + dice;
                     if( seen.find(newPos) == seen.end() ) {
                         vector<int> newNodes = expand(graph,seen,newPos);
                         for(int data: newNodes) {
                             stateQueue.push(data);
                         }
                     }
                 }
            }
            step++;
        }
        return -1;
    }
};