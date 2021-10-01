// bfs + two set + level by level
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> group1;
        unordered_set<int> group2;
        
        
        for( int i = 0; i < graph.size(); i++ ) {
            if(group1.find(i) == group1.end() && group2.find(i) == group2.end()) {
                if(canPartition(graph,group1,group2,i)==false) {
                    return false;
                }
            }
        }
        return true;
       
    }
    
    bool canPartition(vector<vector<int>>& graph,unordered_set<int>& group1,
                     unordered_set<int>& group2,int i) {
        //this queue save the nodes pairs
        // first elem is the node
        // second elem is the group it belong to
        // do this with i first
        queue<pair<int,int>> nodeQueue;
        pair<int,int> firstNode(i,1);
        nodeQueue.push(firstNode);
        group1.insert(i);
        //bfs level by level because I need to group them
        while(nodeQueue.empty()==false) {
            int size = nodeQueue.size();
            for(int popTime = 0; popTime < size; popTime++ ) {
                pair<int,int> frontPair = nodeQueue.front();
                nodeQueue.pop();
                int curNode = frontPair.first;
                int curGroup = frontPair.second;
                //expand it
                vector<int> neighbors = graph[curNode];
                for( int index = 0; index < neighbors.size(); index++ ) {
                    int newNode = neighbors[index];
                    if(group1.find(newNode) == group1.end() 
                       && group2.find(newNode) == group2.end()) {
                        //unexplored node
                        if(curGroup == 1) {
                            pair<int,int> newpair(newNode,2);
                            group2.insert(newNode);
                            nodeQueue.push(newpair);
                        }
                        else {
                            pair<int,int> newpair(newNode,1);
                            group1.insert(newNode);
                            nodeQueue.push(newpair);
                        }
                    }
                    else if(group1.find(newNode) != group1.end()) {
                        if(curGroup==1) {
                            //fail
                            return false;
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        //group2 find it
                        if(curGroup==2){
                            //fail
                            return false;
                        }
                        else {
                            continue;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};
//bfs + two set + normal
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_set<int> group1;
        unordered_set<int> group2;
        
        
        for( int i = 0; i < graph.size(); i++ ) {
            
            if(group1.find(i) == group1.end() && group2.find(i) == group2.end()) {
                if(canPartition(graph,group1,group2,i)==false) {
                    return false;
                }
            }
        }
        return true;
       
    }
    
    bool canPartition(vector<vector<int>>& graph,unordered_set<int>& group1,
                     unordered_set<int>& group2,int i) {
        //this queue save the nodes pairs
        // first elem is the node
        // second elem is the group it belong to
        // do this with i first
        queue<pair<int,int>> nodeQueue;
        pair<int,int> firstNode(i,1);
        nodeQueue.push(firstNode);
        group1.insert(i);
        //bfs level by level because I need to group them
        while(nodeQueue.empty()==false) {
            
                pair<int,int> frontPair = nodeQueue.front();
                nodeQueue.pop();
                int curNode = frontPair.first;
                int curGroup = frontPair.second;
                //expand it
                vector<int> neighbors = graph[curNode];
                for( int index = 0; index < neighbors.size(); index++ ) {
                    int newNode = neighbors[index];
                    if(group1.find(newNode) == group1.end() 
                       && group2.find(newNode) == group2.end()) {
                        //unexplored node
                        if(curGroup == 1) {
                            pair<int,int> newpair(newNode,2);
                            group2.insert(newNode);
                            nodeQueue.push(newpair);
                        }
                        else {
                            pair<int,int> newpair(newNode,1);
                            group1.insert(newNode);
                            nodeQueue.push(newpair);
                        }
                    }
                    else if(group1.find(newNode) != group1.end()) {
                        if(curGroup==1) {
                            //fail
                            return false;
                        }
                        else {
                            continue;
                        }
                    }
                    else {
                        //group2 find it
                        if(curGroup==2){
                            //fail
                            return false;
                        }
                        else {
                            continue;
                        }
                    }
                }
            
        }
        return true;
        
    }
};

//dfs 
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int len = graph.size();
        vector<int> seen(len,-1);
        for( int i = 0; i < graph.size(); i++ ) {
            if(graph[i].size() == 0) {
                continue;
            }
            bool ret = canPartition(graph,seen,i);
            if(ret==false) {
                return false;
            }
        }
        return true;
       
    }
    
    bool canPartition(vector<vector<int>>& graph, vector<int>& seen, int curNode) {
        
        if( seen[curNode] == -1 ) {
            seen[curNode] = 1;
        }
        
        vector<int> neighbors = graph[curNode];
        for(int index = 0; index < neighbors.size(); index++ ) {
            int neighbor = neighbors[index];
            if( seen[neighbor] == -1 ) {
                if(seen[curNode] == 1 ) {
                    seen[neighbor] = 2;
                }
                else {
                    seen[neighbor] = 1;
                }
                bool valid = canPartition(graph,seen,neighbor);
                if(valid == false) {
                    return false;
                }
                
            }
            if( seen[neighbor] == seen[curNode] ) {
                return false;
            }
        }
        return true;
    }
   
};