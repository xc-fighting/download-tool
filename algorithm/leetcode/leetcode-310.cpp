class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if( edges.size() == 0 ) {
            vector<int> result;
            result.push_back(0);
            return result;
        }
        unordered_map<int,vector<int>> graph;
        for( int node = 0; node < n; node++ ) {
            graph[node] = vector<int>();
        }
        vector<int> indegrees(n,0);
        for( int index = 0; index < edges.size(); index++ ) {
            int n1 = edges[index][0];
            int n2 = edges[index][1];
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
            indegrees[n1]++;
            indegrees[n2]++;
        }
        
        int NumNodes = n;
        
        queue<int> leafNodes;
        
        for(int node = 0; node < n; node++) {
            if(indegrees[node] == 1) {
                leafNodes.push(node);
               
            }
        }
        
        
        
        while( NumNodes > 2 ) {
            int size = leafNodes.size();
            for(int i = 0; i < size; i++ ) {
                NumNodes--;
                int frontNode = leafNodes.front();
                leafNodes.pop();
                vector<int> neighbors = graph[frontNode];
                for(int neighbor:neighbors){
                    indegrees[neighbor]--;
                    
                    if(indegrees[neighbor] == 1) {
                        leafNodes.push(neighbor);
                    }
                }
            }
        }
        vector<int> result;
        while(leafNodes.empty()==false) {
            result.push_back(leafNodes.front());
            leafNodes.pop();
        }
        return result;
    }
};