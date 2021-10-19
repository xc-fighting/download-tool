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
    TreeNode* balanceBST(TreeNode* root) {
         vector<TreeNode*> nodelist;
         inOrder(root,nodelist);
         return getBST(nodelist,0,nodelist.size()-1);
    }
    
    void inOrder(TreeNode* root, vector<TreeNode*>& nodeQueue) {
        if( root == nullptr ) {
            return;
        }
        inOrder(root->left, nodeQueue);
        
        nodeQueue.push_back(root);
        inOrder(root->right, nodeQueue);
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    
    TreeNode* getBST(vector<TreeNode*>& nodelist, int left, int right) {
        if( left > right ) {
            return nullptr;
        }
        int mid = left + (right-left)/2;
        TreeNode* root = nodelist[mid];
        root->left = getBST(nodelist,left,mid-1);
        root->right = getBST(nodelist,mid+1,right);
        return root;
    }
};