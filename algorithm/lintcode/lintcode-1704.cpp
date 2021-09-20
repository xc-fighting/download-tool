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
     * @param root: the root node
     * @param L: an integer
     * @param R: an integer
     * @return: the sum
     */
    int rangeSumBST(TreeNode * root, int L, int R) {
        // write your code here.
        vector<int> sum;
        inorderTraverse( root, L, R, sum );
        int result = 0;
        for( int elem: sum ) {
            result += elem;
        }
        return result;
    }

    void inorderTraverse(TreeNode* root, int L, int R, vector<int>& sum ) {
         if( root == nullptr ) {
             return;
         }
         inorderTraverse( root->left, L, R, sum );
         int value = root->val;
         if( value >= L && value <= R ) {
             sum.push_back(value);
         }
         inorderTraverse( root->right, L, R, sum );
         return;
    }
};

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
     * @param root: the root node
     * @param L: an integer
     * @param R: an integer
     * @return: the sum
     */
    int rangeSumBST(TreeNode * root, int L, int R) {
        // write your code here.
       stack<TreeNode*> nodeStack;
       TreeNode* cur = root;
       int sum = 0;
       while( cur != nullptr || nodeStack.empty() == false ) {
           if( cur != nullptr ) {
               nodeStack.push(cur);
               cur = cur->left;
           }
           else {
               TreeNode* topNode = nodeStack.top();
               nodeStack.pop();
               if( topNode->val >= L && topNode->val <= R) {
                    sum += topNode->val;
               }
               
               cur = topNode->right;
           }
       }
       return sum;
    }

    
};