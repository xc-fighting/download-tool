/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr)
        {
            return nullptr;
        }
        map<Node*,Node*> copy_map;
        return deepCopy(node,copy_map);
        
    }
    
    Node* deepCopy(Node* curNode, map<Node*,Node*>& copy_map)
    {
        if(copy_map.find(curNode) != copy_map.end())
        {
            return copy_map[curNode];
        }
        int value = curNode->val;
        Node* newNode = new Node(value);
        copy_map[curNode] = newNode;
        for(int i=0;i<curNode->neighbors.size();i++)
        {
            Node* curChild = curNode->neighbors[i];
            Node* copyChild = deepCopy(curChild,copy_map);
            newNode->neighbors.push_back(copyChild);
        }
        return newNode;
    }
};