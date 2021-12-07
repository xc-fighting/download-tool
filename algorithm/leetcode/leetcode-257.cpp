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
    void traverse(TreeNode* root, vector<string>& result, string curPath) {
        if(root == nullptr) {
            return;
        }
        
        if(root->left == nullptr && root->right == nullptr) {
            curPath += to_string(root->val);
            result.push_back(curPath);
            return;
        }
        
        curPath += to_string(root->val);
        traverse(root->left, result, curPath + "->");
        traverse(root->right, result, curPath + "->");
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        traverse(root, result, "");
        return result;
    }
};
