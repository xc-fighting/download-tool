class Solution {
private:
    bool find;
    vector<string> result;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int> ticketMap;
        for( int index = 0; index < tickets.size(); index++ ) {
            vector<string> edge = tickets[index];
            string from = edge[0];
            string to = edge[1];
            graph[from].push_back(to);
            string ticketStr = from + ":" + to;
            if( ticketMap.find(ticketStr) == ticketMap.end() ) {
                ticketMap[ticketStr] = 0;
            } 
            ticketMap[ticketStr]++;
        }
        unordered_map<string,vector<string>>::iterator itr = graph.begin();
        for(;itr != graph.end(); itr++ ) {
            string key = itr->first;
            sort(graph[key].begin(),graph[key].end());
        }
        int ticketSize = tickets.size();
        this->find = false;
        this->result = vector<string>();
        
        vector<string> curPath;
        traverse(graph,ticketMap,curPath,"JFK",ticketSize+1);
        return result;
    }
    
    void traverse(unordered_map<string,vector<string>>& graph, unordered_map<string,int>& ticketMap,
                  vector<string>& curPath, 
                  string startCity, int cityleft ) {
        if( cityleft == 1 ) {
            curPath.push_back(startCity);
            result = vector<string>(curPath);
            curPath.pop_back();
            find = true;
            return;
        }
        
        curPath.push_back(startCity);
        for(string neighbor: graph[startCity]) {
            if(find) {
                return;
            }
            string ticket = startCity + ":" + neighbor;
            if(ticketMap[ticket] > 0) {
                ticketMap[ticket]--;
                traverse(graph,ticketMap,curPath,neighbor,cityleft-1);
                ticketMap[ticket]++;
            }
        }
        curPath.pop_back();
    }
};