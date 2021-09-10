class Solution {
public:
    /**
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        unordered_map<int,vector<int>> graph;
        vector<int> indegree(numCourses,0);
        for( int i=0; i<numCourses; i++ ) {
            graph[i] = vector<int>();
        }
        for( pair<int,int> edge: prerequisites ) {
             int pre = edge.second;
             int cur = edge.first;
             graph[pre].push_back(cur);
             indegree[cur]++;
        }
        queue<int> courseQueue;
        for( int i=0; i < numCourses; i++ ) {
             if( indegree[i] == 0 ) {
                 courseQueue.push(i);
             }
        }
        while( courseQueue.empty() == false ) {
            int size = courseQueue.size();
            for( int i=0; i< size; i++ ) {
                int frontCourse = courseQueue.front();
                courseQueue.pop();
                for( int neighbor: graph[frontCourse] ) {
                     indegree[neighbor]--;
                     if( indegree[neighbor] == 0 ) {
                         courseQueue.push(neighbor);
                     }
                }
            }
        }

        for(int i=0;i<numCourses;i++) {
             if( indegree[i] != 0 ) {
                  return false;
             }
        }
        return true;
    }
};