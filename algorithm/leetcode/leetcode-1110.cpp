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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> deleteSet;
        for(int i=0;i<to_delete.size();i++) {
            deleteSet.insert(to_delete[i]);
        }
        vector<TreeNode*> forest;
        TreeNode* newroot = traverse(forest,root,deleteSet);
        if(newroot != nullptr) {
            forest.push_back(newroot);
        }
        return forest;
    }
    TreeNode* traverse(vector<TreeNode*>& forest,TreeNode* root,unordered_set<int>& to_delete) {
        if(root == nullptr) {
            return nullptr;
        }
        if(to_delete.find(root->val) != to_delete.end()) {
            to_delete.erase(root->val);
            TreeNode* newleft = traverse(forest,root->left,to_delete);
            TreeNode* newright = traverse(forest,root->right,to_delete);
            if(newleft != nullptr) {
                 forest.push_back(newleft);
            }
            if(newright != nullptr) {
                forest.push_back(newright);
            }
            
            return nullptr;
        }
        root->left = traverse(forest,root->left,to_delete);
        root->right = traverse(forest,root->right,to_delete);
        
        return root;
    }
};