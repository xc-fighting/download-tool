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
class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double result = 0.0;
        traverse(root,&result);
        return result;
    }
    
    vector<int> traverse(TreeNode* root,double* result)
    {
         if(root==nullptr)
         {
             return vector<int>(2,0);
         }
         vector<int> leftpart = traverse(root->left,result);
         vector<int> rightpart = traverse(root->right,result);
         int totalNodes = 1 + leftpart[0] + rightpart[0];
         int totalSum = root->val + leftpart[1] + rightpart[1];
         double currentAve = (double)(1.0 * totalSum/totalNodes);
         if(currentAve > (*result))
         {
             *result = currentAve;
         }
         vector<int> ret;
         ret.push_back(totalNodes);
         ret.push_back(totalSum);
         return ret;
    }
};