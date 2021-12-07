/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> nodeStack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* cur = root;
        while(cur != nullptr) {
            nodeStack.push(cur);
            cur = cur->left;
        }
        return;
    }
    
    int next() {
        if(nodeStack.empty() == true) {
            return -1;
        }
        
        TreeNode* topNode = nodeStack.top();
        nodeStack.pop();
        int ret = topNode->val;
        TreeNode* rightChild = topNode->right;
        while(rightChild != nullptr) {
            nodeStack.push(rightChild);
            rightChild = rightChild->left;
        }
        return ret;
    }
    
    bool hasNext() {
        if(nodeStack.empty() == true) {
            return false;
        }
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
