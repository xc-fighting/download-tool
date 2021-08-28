/*
Description
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
(Path sum is the sum of the weights of nodes on the path between two nodes.)

Example
Example 1:

Input:

tree = {2}
Output:

2
Explanation:

There is only one node 2
Example 2:

Input:

tree = {1,2,3}
Output:

6
Explanation:

As shown in the figure below, the longest path is 2-1-3
      1
     / \
    2   3
*/






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
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode * root) {
        // write your code here
        vector<int> result =  getMaxPath(root);
        return result[0];
    }
    
    /*
         12
        /  \
        3   -24
        /\   /\
       56 5  100 -250
       this function return three thing in a vector [currentMaxPath,maxSumPath start from root 
       (could be root itself, root -> some where left,root-> somewhere right )]
    */
    vector<int> getMaxPath(TreeNode* root)
    {
       if(root==nullptr)
       {
           return vector<int>{INT_MIN,0}; 
       }
       if(root->left == nullptr && root->right == nullptr)
       {
           return vector<int>{root->val,root->val};
       }
       vector<int> leftRet = getMaxPath(root->left);
       vector<int> rightRet = getMaxPath(root->right);
       int leftMax = leftRet[1] + root->val;
       int rightMax = rightRet[1] + root->val;

       int currentMax = max(root->val,max(leftMax,rightMax));


       int leftmaxpath = leftRet[0];
       int rightmaxpath = rightRet[0];
       int candidate1 = max(leftmaxpath,rightmaxpath);
       int fullpath = root->val + leftRet[1] + rightRet[1];
      
       int singlenode = root->val;
       int candidate2 = max(fullpath,singlenode);
       int currentMaxPath = max(candidate1,max(candidate2,currentMax));

       return vector<int>{currentMaxPath,currentMax};


    }
};