class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> seen(n,0);
        unordered_map<int,vector<int>> graph;
        for(int node = 0; node < n; node++ ) {
            graph[node] = vector<int>();
        }
        for( int index = 0; index < edges.size(); index++ ) {
            int prev = edges[index][0];
            int next = edges[index][1];
            graph[prev].push_back(next);
        }
        
        return canReachDestination(graph,source,destination,seen);
    }
    
    bool canReachDestination(unordered_map<int,vector<int>>& graph, int src, int dst, vector<int>& seen) {
         if( src == dst ) {
             if( graph[dst].size() > 0 ) {
                  return false; 
             }
             return true;
         }
         //means src is visiting
         seen[src] = 1;
         vector<int> neighbors = graph[src];
         if( neighbors.size() == 0 ) {
             return false;
         }
         for( int index = 0; index < neighbors.size(); index++ ) {
             int next = neighbors[index];
             if( seen[next] == 1 ) {
                 return false;
             }
             bool canReach = canReachDestination(graph, next, dst, seen);
             if( canReach == false ) {
                 return false;
             }
         }
         seen[src] = 2;
         return true;
    }
};