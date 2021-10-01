struct compare {
public:
    bool operator()(pair<int,int>& lhs, pair<int,int>& rhs) {
        if(lhs.second < rhs.second) {
            return false;
        }
        return true;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //construct the graph
        vector<vector<int>> graph(n+1,vector<int>(n+1,INT_MAX));
        for( int index = 0; index < times.size(); index++ ) {
            vector<int> entry = times[index];
            int src = entry[0];
            int dst = entry[1];
            int time = entry[2];
            graph[src][dst] = time;
        }
        
        //this map record the shortest time it takes to reach
        // a node from k
        vector<int> distanceMap(n+1,INT_MAX);
        vector<bool> seen(n+1,false);
        distanceMap[k] = 0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,compare> pq;
        pq.push(pair<int,int>(k,0));
        while(pq.empty()==false) {
            pair<int,int> topPair = pq.top();
            pq.pop();
            if( seen[topPair.first] == true ) {
                //do nothing
                continue;
            }
            //expand the current pair
            int curNode = topPair.first;
            int curWeight = topPair.second;
            vector<int> neighbors = graph[curNode];
            for( int index = 1; index <= n; index++ ) {
                if(neighbors[index] == INT_MAX) {
                    continue;
                }
                int weight = neighbors[index];
                if(weight + curWeight < distanceMap[index]) {
                    //final ans
                    distanceMap[index] = weight + curWeight;
                    pq.push(pair<int,int>(index,distanceMap[index]));
                }
            }
            
            seen[curNode] = true;
        }
        
        for(int i=1;i<=n;i++) {
            if(seen[i] == false) {
                //cout<<"return here:"<<i<<endl;
                return -1;
            }
        } 
        
        int maxTime = -1;
        for(int i=1;i<=n;i++) {
            maxTime = max(maxTime, distanceMap[i]);
        }
        return maxTime;
        
    }
};