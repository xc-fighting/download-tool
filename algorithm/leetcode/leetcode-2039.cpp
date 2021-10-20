class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int>> graph(n,vector<int>());
       
        for( int index = 0; index < edges.size(); index++ ) {
            int server1 = edges[index][0];
            int server2 = edges[index][1];
            graph[server1].push_back(server2);
            graph[server2].push_back(server1);
        }
      //  cout<<"here first"<<endl;
        vector<int> distanceMap(n,-1);
        distanceMap[0] = 0;
        queue<int> serverQueue;
        serverQueue.push(0);
        vector<bool> visited(n,false);
        visited[0] = true;
        int dis = 0;
        while( serverQueue.empty() == false ) {
            int size = serverQueue.size();
            for(int index = 0; index < size; index++) {
                int frontServer = serverQueue.front();
                serverQueue.pop();
                for( int nextIndex = 0; nextIndex < graph[frontServer].size(); nextIndex++) {
                    int nextServer = graph[frontServer][nextIndex];
                    if(visited[nextServer] == false){
                        visited[nextServer] = true;
                        distanceMap[nextServer] = dis + 1;
                        serverQueue.push(nextServer);
                    }
                }
            }
            dis++;
        }
        vector<int> timeMap(n,0);
        for(int index = 0; index < n; index++ ) {
            timeMap[index] = distanceMap[index] * 2;
        }
      //  cout<<"here"<<endl;
        int result = 0;
        for( int index = 0; index < n; index++ ) {
            if(index == 0) {
                continue;
            }
            if(patience[index] >= timeMap[index]) {
                result = max(result,timeMap[index]);
                continue;
            }
            int timeTraverse = timeMap[index];
            int diff = timeTraverse - patience[index];
            int packages = ( diff / patience[index] );
            if( diff % patience[index] != 0 ) {
                packages++;
            }
            int finalTime = packages*patience[index] + timeTraverse;
            result = max(result, finalTime);
        }
        return result+1;
        
    }
};