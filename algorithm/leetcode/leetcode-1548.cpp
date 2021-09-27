struct info {
public:
    int cost;
    vector<vector<int>> citylist;
    info(int cost) {
        this->cost = cost;
        this->citylist = vector<vector<int>>();
    }
    
};
class Solution {
public:
    vector<int> mostSimilar(int n, vector<vector<int>>& roads, vector<string>& names, vector<string>& targetPath) {
        
         unordered_map<int,vector<int>> graph;
         for( int i = 0; i < n; i++ ) {
             graph[i] = vector<int>();
         }
         
         //initialize the graph
         for( int index = 0; index < roads.size(); index++ ) {
             int city1 = roads[index][0];
             int city2 = roads[index][1];
             graph[city1].push_back(city2);
             graph[city2].push_back(city1);
         }
         
         int targetSize = targetPath.size();
         vector<vector<info*>> memo(n,vector<info*>(targetSize,nullptr));
         int result = 1000000000;
         info* candidate = nullptr;
         for( int city = 0; city < n; city++ ) {
             
             info* temp = getCost( graph, memo, city, names, 0, targetPath );
             if(temp->cost < result) {
                 result = temp->cost;
                 candidate = temp;
             }
         }
         return candidate->citylist[0];
    }
    
    info* getCost(unordered_map<int,vector<int>>& graph, vector<vector<info*>>& memo, int curCity, 
                vector<string>& names, int curIndex, 
                vector<string>& targetPath) {
        
        if( curIndex == targetPath.size() ) {
            info* base = new info(0);
            base->citylist.push_back(vector<int>());
            return base;
        }
        
        if( memo[curCity][curIndex] != nullptr ) {
             return memo[curCity][curIndex];
        }
        int result = 0;
        if( names[curCity].compare(targetPath[curIndex]) != 0 ) {
            result = 1;
        }
        
        int temp = 1000000000;
        info* candidate = nullptr;
        vector<int> nextCitys = graph[curCity];
        for( int i = 0; i < nextCitys.size(); i++ ) {
            info* childret = getCost( graph, memo, nextCitys[i], names, curIndex + 1, targetPath );
            if( childret->cost < temp ) {
                temp = childret->cost;
                candidate = childret;
            }
        }
        
        info* ret = new info(result+temp);
        for( int i=0; i<candidate->citylist.size(); i++ ) {
            vector<int> tempbuffer;
            tempbuffer.push_back(curCity);
            vector<int>& curchildren = candidate->citylist[i];
            for(int j=0;j<curchildren.size();j++) {
                tempbuffer.push_back(curchildren[j]);
            }
            ret->citylist.push_back(tempbuffer);
        }
        
        memo[curCity][curIndex] = ret;
        return ret;
    }
};