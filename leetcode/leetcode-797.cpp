class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int num = graph.size();
        vector<bool> visited(num,false);
        vector<vector<int>> result;
        vector<int> curpath;
        dfs(graph,visited,0,num-1,curpath,result);
        return result;
    }
    void dfs(vector<vector<int>>& graph,vector<bool>& visited,
             int start,int end,vector<int>& curPath, 
             vector<vector<int>>& allPaths)
    {
        if(start == end)
        {
            curPath.push_back(start);
            visited[start] = true;
            allPaths.push_back(vector<int>(curPath));
            visited[start] = false;
            curPath.pop_back();
            return;
        }
        curPath.push_back(start);
        visited[start] = true;
        for(int i=0;i<graph[start].size();i++)
        {
            int neighbor = graph[start][i];
            if(visited[neighbor]==false)
            {
                dfs(graph,visited,neighbor,end,curPath,allPaths);
            }
            
        }
        curPath.pop_back();
        visited[start] = false;
        return;
    }
};
