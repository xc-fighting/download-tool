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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) {
            return result;
        }
        map<int, int> heightValue;
        traverse(root, heightValue, 0);
        for(auto entry: heightValue) {
            result.push_back(entry.second);
        }
        return result;
    }
    
    void traverse(TreeNode* root, map<int,int>& heightValue, int height) {
        if(root == nullptr) {
            return;
        }
        
        heightValue[height] = root->val;
        
        traverse(root->left, heightValue, height + 1);
        traverse(root->right, heightValue, height + 1);
        
    }
};
