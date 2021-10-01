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
    int maxAncestorDiff(TreeNode* root) {
        vector<int> result = getDiffRecursive(root);
        return result[0];
    }
    
    // result[0] is the current largest diff
    // result[1] is the min value 
    // result[2] is the max value
    vector<int> getDiffRecursive(TreeNode* root) {
       
        if( root->left == nullptr && root->right == nullptr ) {
            vector<int> result(3,-1);
            result[0] = 0;
            result[1] = root->val;
            result[2] = root->val;
        }
        
        int curMin = root->val;
        int curMax = root->val;
        int diff = 0;
     //   cout<<"root:"<<root->val<<endl;
        if( root->left != nullptr ) {
            vector<int> leftpart = getDiffRecursive(root->left);
         //   cout<<"root value:"<<root->val<<endl;
            int diff1 = abs(leftpart[1] - root->val );
            int diff2 = abs(leftpart[2] - root->val );
            int diff3 = leftpart[0];
          //  cout<<diff1<<" "<<diff2<<endl;
            diff = max( diff, max(diff1,diff2) );
            diff = max(diff, diff3);
            curMax = max(curMax, leftpart[2]);
            curMin = min(curMin, leftpart[1]);
        }
        
        if( root->right != nullptr ) {
            vector<int> rightpart = getDiffRecursive(root->right);
         //   cout<<"root value:"<<root->val<<endl;
            int diff1 = abs(rightpart[1] - root->val );
            int diff2 = abs(rightpart[2] - root->val );
            int diff3 = rightpart[0];
          //  cout<<diff1<<" "<<diff2<<endl;
            diff = max( diff, max(diff1,diff2) );
            diff = max( diff, diff3 );
           // cout<<"the diff:"<<diff<<endl;
            curMax = max(curMax, rightpart[2]);
            curMin = min(curMin, rightpart[1]);
        }
        
        vector<int> result(3,-1);
        result[0] = diff;
        result[1] = curMin;
        result[2] = curMax;
        
        return result;
        
    }
};