//solution 1, use the union find to check
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<int> nodes(n,-1);
        for(int i=0;i<n;i++)
        {
            nodes[i] = i;
        }
        for(int i=0;i<edges.size();i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int root1 = findParent(nodes,node1);
            int root2 = findParent(nodes,node2);
            if(root1!=root2)
            {
                nodes[root1]=root2;
            }
            
        }
        return findParent(nodes,start) == findParent(nodes,end);
    }
    int findParent(vector<int>& nodes, int cur)
    {
        if(nodes[cur]==cur)
        {
            return cur;
        }
        int current = cur;
        
        
        while(nodes[current] != current)
        {
            current = nodes[current];
        }
        nodes[cur] = current;
        return nodes[cur];
    }
};
//solution 2, use dfs to check TLE
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
       map<int,vector<int>> graph;
       for(int i=0;i<edges.size();i++)
       {
           int node1 = edges[i][0];
           int node2 = edges[i][1];
           if(graph.find(node1) == graph.end())
           {
               graph[node1] = vector<int>();
           }
           if(graph.find(node2) == graph.end())
           {
               graph[node2] = vector<int>();
           }
           graph[node1].push_back(node2);
           graph[node2].push_back(node1);
       }
       vector<bool> visited(n,false);
       return pathExist(graph,visited,start,end);
        
    }
    
    bool pathExist(map<int,vector<int>>& graph,vector<bool>& visited,int cur,int end)
    {
        if(cur==end)
        {
            return true;
        }
        visited[cur] = true;
        bool find = false;
        for(int i=0;i<graph[cur].size();i++)
        {
            int neighbor = graph[cur][i];
            if(visited[neighbor]==false)
            {
                bool ret = pathExist(graph,visited,neighbor,end);
                if(ret)
                {
                    find = true;
                    break;
                }
            }
        }
        visited[cur] = false;
        return find;
    }
    
};

// iterative dfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
       if(start==end)
       {
           return true;
       }
       map<int,vector<int>> graph;
       for(int i=0;i<edges.size();i++)
       {
           int node1 = edges[i][0];
           int node2 = edges[i][1];
           if(graph.find(node1) == graph.end())
           {
               graph[node1] = vector<int>();
           }
           if(graph.find(node2) == graph.end())
           {
               graph[node2] = vector<int>();
           }
           graph[node1].push_back(node2);
           graph[node2].push_back(node1);
       }
       vector<bool> visited(n,false);
       stack<int> dfsStack;
       visited[start] = true;
       dfsStack.push(start);
       while(dfsStack.empty()==false)
       {
           int topNode = dfsStack.top();
           dfsStack.pop();
           for(int i=0;i<graph[topNode].size();i++)
           {
               int neighbor = graph[topNode][i];
               if(neighbor==end)
               {
                   return true;
               }
               if(visited[neighbor]==false)
               {
                   visited[neighbor] = true;
                   dfsStack.push(neighbor);
               }
           }
       }
       return false;
        
    }
    
};

//solution 3 bfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
       if(start==end)
       {
           return true;
       }
       map<int,vector<int>> graph;
       for(int i=0;i<edges.size();i++)
       {
           int node1 = edges[i][0];
           int node2 = edges[i][1];
           if(graph.find(node1) == graph.end())
           {
               graph[node1] = vector<int>();
           }
           if(graph.find(node2) == graph.end())
           {
               graph[node2] = vector<int>();
           }
           graph[node1].push_back(node2);
           graph[node2].push_back(node1);
       }
       vector<bool> visited(n,false);
       queue<int> bfsqueue;
       bfsqueue.push(start);
       visited[start] = true;
       while(bfsqueue.empty()==false)
       {
           int frontNode = bfsqueue.front();
           bfsqueue.pop();
           for(int i=0;i<graph[frontNode].size();i++)
           {
               int neighbor = graph[frontNode][i];
               if(neighbor==end)
               {
                   return true;
               }
               if(visited[neighbor]==false)
               {
                   visited[neighbor] = true;
                   bfsqueue.push(neighbor);
               }
           }
       }
       return false;
        
    }
    
   
    
};