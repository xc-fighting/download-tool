/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr) {
            return nullptr;
        }
        stack<Node*> traverseStack;
        Node* curNode = root;
        Node* head = nullptr;
        Node* tail = nullptr;
        while( curNode != nullptr || traverseStack.empty() == false ) {
            if( curNode != nullptr ) {
                traverseStack.push(curNode);
                curNode = curNode->left;
            }
            else {
                Node* topNode = traverseStack.top();
                traverseStack.pop();
                if(head == nullptr) {
                    head = topNode;
                    tail = topNode;
                }
                else {
                    tail->right = topNode;
                    topNode->left = tail;
                    tail = topNode;
                }
                curNode = topNode->right;
            }
        }
        tail->right = head;
        head->left = tail;
        return head;
    }
};
