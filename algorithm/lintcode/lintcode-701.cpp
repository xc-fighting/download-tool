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
     * @param root: given BST
     * @param minimum: the lower limit
     * @param maximum: the upper limit
     * @return: the root of the new tree 
     */
    TreeNode * trimBST(TreeNode * root, int minimum, int maximum) {
        // write your code here
        if( root == nullptr ) {
            return nullptr;
        }
        if( root->val >= minimum && root->val <= maximum ) {
            root->left = trimBST(root->left, minimum, maximum);
            root->right = trimBST(root->right, minimum, maximum);
            return root;
        }

        if( root->val < minimum ) {
            return trimBST(root->right,minimum,maximum);
        }

        if(root->val > maximum) {
            return trimBST(root->left,minimum,maximum);
        }
    }
};