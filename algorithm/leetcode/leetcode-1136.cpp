class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int semester = 0;
        vector<int> indegrees(n+1,0);
        vector<vector<int>> graph(n+1,vector<int>());
        for(int i=0;i<relations.size();i++)
        {
            vector<int> relation = relations[i];
            int pre = relation[0];
            int next = relation[1];
            graph[pre].push_back(next);
            indegrees[next]++;
        }
        
        queue<int> courseQueue;
        for(int i=1;i<=n;i++)
        {
            if(indegrees[i]==0)
            {
                courseQueue.push(i);
            }
        }
        
        while(courseQueue.empty()==false)
        {
            int size = courseQueue.size();
            for(int i=0;i<size;i++)
            {
                int topNode = courseQueue.front();
                courseQueue.pop();
                vector<int> neighbors = graph[topNode];
                for(int j=0;j<neighbors.size();j++)
                {
                    int neighbor = neighbors[j];
                    indegrees[neighbor]--;
                    if(indegrees[neighbor]==0)
                    {
                        courseQueue.push(neighbor);
                    }
                }
            }
            semester++;
        }
        for(int i=1;i<=n;i++)
        {
            if(indegrees[i]!=0)
            {
                return -1;
            }
        }
        return semester;
    }
};