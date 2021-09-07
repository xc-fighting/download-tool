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
     * @param root: the root of the given tree
     * @return: the values of the nodes you can see ordered from top to bottom
     */
    vector<int> rightSideView(TreeNode * root) {
        // write your code here
        int depth = getDepth(root);
        // pair.first is the value pair.second is the distance
        vector<int> depthCache(depth,-1);
        traverse(root,depthCache,0);
        vector<int> result;
        for(int i=0;i<depthCache.size();i++)
        {
            result.push_back(depthCache[i]);
        }
        return result;
    }

    void traverse(TreeNode* root,vector<int>& depthCache, int depth)
    {
       if(root == nullptr)
       {
           return;
       }
       int value = root->val;
       depthCache[depth] = value;
       
       traverse(root->left,depthCache,depth+1);
       traverse(root->right,depthCache,depth+1);
       return;
    }

    int getDepth(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        return 1+ max(leftDepth,rightDepth);
    }
};