/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
private:
    vector<string> split(string input,string splitter)
    {
        vector<string> result;
        string tempstr = input+splitter;
        int pos = tempstr.find(splitter);
        int splitterSize = splitter.size();
        while(pos != string::npos)
        {
            string component = tempstr.substr(0,pos);
            result.push_back(component);
            tempstr = tempstr.substr(pos+splitterSize);
            pos = tempstr.find(splitter);
        }
        return result;
    }
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if(root==nullptr)
        {
            return "";
        }
        queue<Node*> nodeQueue;
        nodeQueue.push(root);
        string result = "";
        while(nodeQueue.empty()==false)
        {
            int size = nodeQueue.size();
            for(int i=0;i<size;i++)
            {
                Node* frontNode = nodeQueue.front();
                nodeQueue.pop();
                int childrenSize = frontNode->children.size();
                string temp = to_string(frontNode->val)+":"+to_string(childrenSize);
                result = result + " " + temp;
                for(Node* child:frontNode->children)
                {
                    nodeQueue.push(child);
                }
            }
        }
        return result;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if(data.size()==0)
        {
            return nullptr;
        }
        data = data.substr(1);
        
        vector<string> strArray = split(data," ");
        vector<pair<int,int>> pairArray;
        for(int i=0;i<strArray.size();i++)
        {
            vector<string> pairs = split(strArray[i],":");
            int value = stoi(pairs[0]);
            int childlen = stoi(pairs[1]);
            pairArray.push_back(pair<int,int>(value,childlen));
        }
        
        int startIndex = 0;
        Node* root = new Node(pairArray[0].first);
        queue<pair<Node*,int>> nodeQueue;
        nodeQueue.push(pair<Node*,int>(root,pairArray[0].second));
        startIndex = 1;
        while(nodeQueue.empty()==false)
        {
            int size = nodeQueue.size();
            
            for(int i=0;i<size;i++)
            {
                pair<Node*,int> frontPair = nodeQueue.front();
                nodeQueue.pop();
                Node* frontNode = frontPair.first;
                int childSize = frontPair.second;
                for(int j = startIndex;j < startIndex+childSize;j++)
                {
                    Node* childNode = new Node(pairArray[j].first);
                    frontNode->children.push_back(childNode);
                    nodeQueue.push(pair<Node*,int>(childNode,pairArray[j].second));
                }
                startIndex = startIndex+ childSize;
            }
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));