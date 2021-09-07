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
    vector<TreeNode*> delMin(TreeNode* root)
    {
        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        vector<TreeNode*> result(2,nullptr);
        while(cur->left != nullptr)
        {
            pre = cur;
            cur = cur->left;
        }
        if(pre==nullptr)
        {
            result[0] = cur;
            result[1] = cur->right;
        }
        else
        {
            pre->left = nullptr;
            pre->left = cur->right;
            cur->right = nullptr;
            result[0] = cur;
            result[1] = root;
        }
        return result;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
        {
            return root;
        }
        if(key > root->val)
        {
            root->right = deleteNode(root->right,key);
            return root;
        }
        else if(key < root->val)
        {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else
        {
            //delete current node
            if(root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            if(root->left == nullptr && root->right != nullptr)
            {
                TreeNode* ret = root->right;
                root->right = nullptr;
                return ret;
            }
            if(root->right == nullptr && root->left != nullptr)
            {
                TreeNode* ret = root->left;
                root->left = nullptr;
                return ret;
            }
            
            vector<TreeNode*> minCombine = delMin(root->right);
            TreeNode* previousLeft = root->left;
            minCombine[0]->right = minCombine[1];
            minCombine[0]->left = previousLeft;
            return minCombine[0];
            
        }
    }
    
};