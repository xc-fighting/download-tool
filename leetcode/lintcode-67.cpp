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
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Inorder in ArrayList which contains node values.
     */
    vector<int> inorderTraversal(TreeNode * root) {
        // write your code here
        vector<int> result;
        TreeNode* current = root;
        stack<TreeNode*> nodeStack;
        
        while(current != nullptr || nodeStack.empty()==false)
        {
            if(current != nullptr)
            {
                nodeStack.push(current);
                current = current->left;
            }
            else
            {
                if(nodeStack.empty()==false)
                {
                    TreeNode* popNode = nodeStack.top();
                    result.push_back(popNode->val);
                    nodeStack.pop();
                    current = popNode->right;
                }
                else 
                {
                    break;
                }
            }
        }
        return result;
    }
};