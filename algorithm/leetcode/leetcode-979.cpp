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
private:
    int moves;
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        getNeeded(root);
        return moves;
    }
    
    int getNeeded(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int diff = root->val - 1;
        int leftneeded = getNeeded(root->left);
        int rightneeded = getNeeded(root->right);
        moves += abs(leftneeded) + abs(rightneeded);
        return leftneeded+rightneeded+diff;
    }
};