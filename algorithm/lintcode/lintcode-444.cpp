class Solution {
private:
   unordered_map<int,int> rootMap;
   bool existLoop;
   int numVertex, numEdge;
   int findParent(int cur) {
       if( rootMap[cur] == cur ) {
           return cur;
       }
       int root = findParent(rootMap[cur]);
       rootMap[cur] = root;
       return root;
   }
public:
    
    Solution() {
        this->existLoop = false;
        this->numVertex = 0;
        this->numEdge = 0;
    }

    /**
     * @param a: the node a
     * @param b: the node b
     * @return: nothing
     */

    void addEdge(int a, int b) {
        // write your code here
        if( rootMap.find(a) == rootMap.end() ) {
            rootMap[a] = a;
            this->numVertex++;
        }
        if( rootMap.find(b) == rootMap.end() ) {
            rootMap[b] = b;
            this->numVertex++;
        }
        this->numEdge++;
        int parentA = findParent(a);
        int parentB = findParent(b);
        if( parentA == parentB ) {
            this->existLoop = true;
        }
        else {
            this->existLoop = false;
            rootMap[parentA] = parentB;
        }
    }

    /**
     * @return: check whether these edges make up a valid tree
     */
    bool isValidTree() {
        // write your code here
        if( this->existLoop ) {
            return false;
        }
        if( (this->numVertex - 1) != this->numEdge) {
            return false;
        }
        return true;
    }
};
