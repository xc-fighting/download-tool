class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        map<int,vector<int>> graph;
        for(int i=0;i<n;i++)
        {
            graph[i] = vector<int>();
        }
        for(int i=0;i<edges.size();i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        vector<bool> visited(n,false);
        int number = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==true)
            {
                continue;
            }
            number++;
            if(findCycle(graph,i,-1,visited))
            {
                return false;
            }
        }
        if(number > 1)
        {
            return false;
        }
        return true;
    }
    
    bool findCycle(map<int,vector<int>>& graph,int currentNode,int preNode,vector<bool>& visited)
    {
        
        visited[currentNode] = true;
        vector<int>& neighbors = graph[currentNode];
        for(int i=0;i<neighbors.size();i++)
        {
            if(neighbors[i]==preNode)
            {
                continue;
            }
            if(visited[neighbors[i]]==true)
            {
                return true;
            }
            else
            {
               bool cycle = findCycle(graph,neighbors[i],currentNode,visited);
               if(cycle)
               {
                   return true;
               }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> parents(n,-1);
        for(int i=0;i<n;i++)
        {
            parents[i] = i;
        }
        int numComponent = n;
        for( int i=0; i<edges.size(); i++ )
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int p1 = findParent(parents,node1);
            int p2 = findParent(parents,node2);
            if(p1 != p2)
            {
                parents[p1] = p2;
                numComponent--;
            }
            else
            {
                //find cycle
                return false;
            }
        }
        if(numComponent == 1)
        {
            return true;
        }
        return false;
    }
    
    int findParent(vector<int>& parents, int current)
    {
        if(parents[current] == current)
        {
            return parents[current];
        }
        int root = findParent(parents,parents[current]);
        parents[current] = root;
        return root;
    }
    
};