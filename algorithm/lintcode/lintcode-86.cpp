/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * BSTIterator iterator = BSTIterator(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */


class BSTIterator {
private:
   stack<TreeNode*> nodeStack;
public:
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        // do intialization if necessary
        
      //  cout<<"init"<<endl;
        TreeNode* curNode = root;
        while( curNode != nullptr ) {
            nodeStack.push(curNode);
           // cout<<"push:"<<curNode->val<<endl;
            curNode = curNode->left;
        }
        
    }

    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
      //  cout<<"this function called"<<endl;
        // write your code here
        if(nodeStack.empty() == true) {
            return false;
        }
        return true;
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode* topNode = nodeStack.top();
        nodeStack.pop();
       // cout<<topNode->val<<endl;
        TreeNode* curNode = topNode->right;
        while( curNode != nullptr ) {
            nodeStack.push(curNode);
            curNode = curNode->left;
        }
        return topNode;
    }
};