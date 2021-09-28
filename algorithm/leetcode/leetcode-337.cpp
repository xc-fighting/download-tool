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
    int rob(TreeNode* root) {
        return getMaxMoney(root,false);
    }
    
    int getMaxMoney(TreeNode* root, bool lastRob) {
         if(root == nullptr) {
             return 0;
         }
         
         int maxMoney = 0;
         if( lastRob == false ) {
             //could try rob it
             int leftMoney = getMaxMoney(root->left, true);
             int rightMoney = getMaxMoney(root->right, true);
             maxMoney = root->val + leftMoney + rightMoney;
         }
        
         //if last if rob or simply not want to rob it
         int notRobLeft = getMaxMoney(root->left, false);
         int notRobRight = getMaxMoney(root->right, false);
         maxMoney = max(maxMoney, notRobLeft+notRobRight);
         return maxMoney;
    }
};