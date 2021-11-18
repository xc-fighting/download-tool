class MyTreeNode {
private:
   int label;
   bool isDeleted;
   vector<MyTreeNode*> children;
   void traverseHelper(MyTreeNode* root, vector<int>& result ) {
       if( root->isDeleted == false ) {
            result.push_back(root->label);
       }
      
       for( int index = 0; index < root->children.size(); index++ ) {
           traverseHelper(root->children[index], result);

       }
       return;
   }
public:
    /**
     * @param val: the node's val
     * @return: a MyTreeNode object
     */
    MyTreeNode(int val) {
        // write your code here
        this->label = val;
        this->isDeleted = false;
        children = vector<MyTreeNode*>();
    }
    
    /**
     * @param root: the root treenode
     * @return: get the traverse of the treenode
     */
    vector<int> traverse(MyTreeNode * root) {
        // write your code here
        vector<int> result;
        traverseHelper(root,result);
        return result;
    }

    /**
     * @param root: the node where added
     * @param value: the added node's value
     * @return: add a node, return the node
     */
    MyTreeNode * addNode(MyTreeNode * root, int value) {
        // write your code here
        MyTreeNode* newNode = new MyTreeNode(value);
        root->children.push_back(newNode);
        return newNode;
    }

    /**
     * @param root: the deleted node
     * @return: nothing
     */
    void deleteNode(MyTreeNode * root) {
        // write your code here
        root->isDeleted = true;
    }
};