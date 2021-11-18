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
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        // write your code here
        vector<int> ret = getDiameter(root);
        return ret[0] - 1;
    }

    vector<int> getDiameter(TreeNode* root)
    {
        //return a vector of two values
        //[current longest nodes,longest path from root->leaf]
        if(root==nullptr)
        {
            return vector<int>{0,0};
        }
        if(root->left == nullptr && root->right == nullptr)
        {
            return vector<int>{1,1};
        }
        vector<int> leftret = getDiameter(root->left);
        vector<int> rightret = getDiameter(root->right);
        int longestPathLeaf = max(1+leftret[1],1+rightret[1]);
        int candidate = leftret[1] + rightret[1] + 1;
        int curMax = max(candidate,max(leftret[0],rightret[0]));
        return vector<int>{curMax,longestPathLeaf};
    }
};



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
     * @param root: a root of binary tree
     * @return: return a integer
     */
    // res[0] means the longest path len
    // res[1] the length start from root
    vector<int> getLongest(TreeNode* root) {
        if( root == nullptr ) {
            vector<int> res(2,0);
            return res;
        }
        vector<int> leftLen = getLongest(root->left);
        vector<int> rightLen = getLongest(root->right);
        int exist = max(leftLen[0],rightLen[0]);
        int pathLen = leftLen[1] + rightLen[1] + 1;
        pathLen = max(pathLen,exist);
        int startFromLen = max(leftLen[1],rightLen[1]) + 1;
        vector<int> res(2,-1);
        res[0] = pathLen;
        res[1] = startFromLen;
        return res;
    }
    int diameterOfBinaryTree(TreeNode * root) {
        // write your code here
        if( root == nullptr ) {
            return 0;
        }
        vector<int> res = getLongest(root);
        return res[0] - 1;
    }
};