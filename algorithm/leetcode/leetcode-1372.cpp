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
    int longestZigZag(TreeNode* root) {
        vector<int> ret = getLongest(root);
        if(ret[0] == 0) {
            return 0;
        }
        return ret[0]-1;
    }
    
    //return three item
    //ret[0] current longest ans
    //ret[1] longest path start from root goes left
    //ret[2] longest path start from root goes right
    vector<int> getLongest(TreeNode* root) {
        if( root == nullptr ) {
            return vector<int>( 3, 0 );
        }
        
        vector<int> leftPart = getLongest(root->left);
        vector<int> rightPart = getLongest(root->right);
        
        int goesRight = 1;
        int goesLeft = 1;
        
        if( root->right != nullptr ) {
            goesRight = max(goesRight, 1 + rightPart[1]);
        }
        
        if( root->left != nullptr ) {
            goesLeft = max(goesLeft, 1 + leftPart[2]);
        }
        
        int candidateMax = max(goesLeft,goesRight);
        int existMax = max(leftPart[0], rightPart[0]);
        
        int newMax = max(candidateMax, existMax);
        vector<int> result(3,0);
        result[0] = newMax;
        result[1] = goesLeft;
        result[2] = goesRight;
        return result;
    }
};