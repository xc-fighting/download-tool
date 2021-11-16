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
     * @param root: the given BST
     * @param p: the given node
     * @return: the in-order predecessor of the given node in the BST
     */
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        // write your code here
        if( p == nullptr ) {
            return nullptr;
        }
        //find the max node in p left tree
        if( p->left != nullptr ) {
              TreeNode* start = p->left;
              while( start != nullptr && start->right != nullptr ) {
                  start = start->right;
              }
              return start;
        }
        else {
            TreeNode* predessor = nullptr;
            TreeNode* cur = root;
            int value = p->val;
            while( cur != nullptr ) {
                if( cur == p ) {
                    break;
                }
                if( cur->val < value ) {
                    predessor = cur;
                    cur = cur->right;
                }
                else {
                    cur = cur->left;
                }
            }
            return predessor;
        }
       
    }
};