class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> graph(n,vector<int>(n,-1));
        vector<vector<int>> memo(n,vector<int>(k+2,-1));
        for( int index = 0; index < flights.size(); index++ ) {
             int from = flights[index][0];
             int to = flights[index][1];
             graph[from][to] = flights[index][2];
        }
        int res = cheapestPriceFrom(graph,memo,src,dst,k+1);
        if( res == INT_MAX ) {
            return -1;
        }
        return res;
    }
    
    int cheapestPriceFrom(vector<vector<int>>& graph, vector<vector<int>>& memo,
                          int src, int dst, int stepLeft) {
        if( stepLeft < 0 ) {
            return INT_MAX;
        }
        if( src == dst ) {
           // cout<<"reach"<<endl;
            return 0;
        }
       // cout<<src<<endl;
        if( memo[src][stepLeft] != -1 ) {
            return memo[src][stepLeft];
        }
        vector<int>& nextCities = graph[src];
        int result = INT_MAX;
        for( int index = 0; index < nextCities.size(); index++ ) {
            if( nextCities[index] != -1 ) {
                int currentCost = nextCities[index];
                int nextCost = cheapestPriceFrom(graph,memo,index,dst,stepLeft-1);
                if( nextCost != INT_MAX ) {
                    result = min( result, nextCost + currentCost );
                }
            }
        }
        memo[src][stepLeft] = result;
        return result;
    }
};