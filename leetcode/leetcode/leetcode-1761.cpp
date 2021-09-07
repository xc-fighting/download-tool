class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n+1,vector<int>(n+1,0));
        vector<int> degrees(n+1,0);
        for(vector<int> edge:edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1][node2] = 1;
            graph[node2][node1] = 1;
            degrees[node1]++;
            degrees[node2]++;
        }
        
        int result = INT_MAX;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                for(int k=j+1;k<=n;k++)
                {
                    //check whether three nodes are trio
                    if(graph[i][j]==1 && graph[j][k] == 1 && graph[i][k] == 1)
                    {
                        //it is a trio
                        // then add degrees together
                        int totalDegree = degrees[i] + degrees[j] + degrees[k];
                        int outerEdges = totalDegree - 6;
                        result = min(result,outerEdges);
                    }
                }
            }
        }
        if(result==INT_MAX)
        {
            return -1;
        }
        return result;
    }
};