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
    int result;
public:
    int minCameraCover(TreeNode* root) {
        result = 0;
        int ret = minimumCamera(root);
        if(ret == 0)
        {
            result++;
        }
        return result;
    }
    
    //0 means not covered
    // 1 means camera there
    // 2 means covered
    int minimumCamera(TreeNode* current)
    {
       if(current == nullptr)
       {
           return 1;
       }
       int leftstate = minimumCamera(current->left);
       int rightstate = minimumCamera(current->right);
       if(leftstate == 0 || rightstate == 0)
       {
           result++;
           return 1;
       }
        
       if( ( current->left != nullptr && leftstate == 1 ) 
           || ( current->right !=nullptr && rightstate == 1) )
       {
           return 2;
       }
       
       return 0;
       
    }
};