//TLE
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
      
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++)
        {
            graph[i] = vector<int>();
        }
        for(vector<int> edge:edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            vector<int> memo(n,-1);
            getDistance(graph,memo,i,0);
            int sum = 0;
          //  cout<<"head node:"<<i<<endl;
            for(int elem:memo)
            {
             //   cout<<elem<<" ";
                sum += elem;
            }
          //  cout<<endl;
            result.push_back(sum);
        }
        return result;
        
    }
    void getDistance(unordered_map<int,vector<int>>& graph,vector<int>& currentDistance,int cur,int curDistance)
    {
        
        currentDistance[cur] = curDistance;
        for(int child:graph[cur])
        {
            if(currentDistance[child] != -1)
            {
                continue;
            }
            getDistance(graph,currentDistance,child,curDistance+1);
        }
        return;
    }
};


class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
      
        // initialize the graph with edges
        unordered_map<int,vector<int>> graph;
        for(int i=0;i<n;i++)
        {
            graph[i] = vector<int>();
        }
        for(vector<int> edge:edges)
        {
            int node1 = edge[0];
            int node2 = edge[1];
            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        
        // counts keep track of subtree count start from i
        vector<int> counts(n,0);
        vector<bool> seen(n,false);
        
        vector<int> ret = traverse(graph,0,counts,seen);
      /*  for(int count:counts)
        {
            cout<<count<<" ";
        }
        cout<<endl; */
        int sum = ret[0];
        vector<int> result(n,-1);
        result[0] = sum;
        seen.clear();
        seen = vector<bool>(n,false);
        traverse(graph,0,-1,counts,seen,result,n);
        return result;
        
    }
    
    vector<int> traverse(unordered_map<int,vector<int>>& graph, int root,vector<int>& counts,vector<bool>& seen)
    {
        //result[0] means sum start from root
        //result[1] means number of nodes start from root
        seen[root] = true;
        vector<int> result(2,0);
        vector<int>& children = graph[root];
        for(int child:children)
        {
            if(seen[child] == true)
            {
                continue;
            }
            vector<int> childret = traverse(graph,child,counts,seen);
            result[1] += childret[1];
            result[0] += childret[1] + childret[0];
         }
         result[1]++;
         counts[root] = result[1];
         return result;
    }
    
    void traverse(unordered_map<int,vector<int>>& graph,int current,int parent,
                  vector<int>& counts,vector<bool>& seen,vector<int>& result,int n)
    {
        
        if(parent != -1)
        {
            int sumParent = result[parent];
            int countParent = n - counts[current];
            int countCurrent = counts[current];
            int sumCurrent = sumParent + countParent - countCurrent;
            result[current] = sumCurrent;
        }
        seen[current] = true;
        vector<int>& children = graph[current];
        for(int child:children)
        {
           if(seen[child] == true)
           {
               continue;
           }
           traverse(graph,child,current,counts,seen,result,n);
        }
        return;
    }
        
    
};