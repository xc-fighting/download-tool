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
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if(root == nullptr)
        {
            return result;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(nodeQueue.empty()==false)
        {
            int size = nodeQueue.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* frontNode = nodeQueue.front();
                nodeQueue.pop();
                temp.push_back(frontNode->val);
                if(frontNode->left != nullptr)
                {
                    nodeQueue.push(frontNode->left);
                }
                if(frontNode->right != nullptr)
                {
                    nodeQueue.push(frontNode->right);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};