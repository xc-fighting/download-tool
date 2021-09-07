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
private:
   TreeNode* candidate;
   double candidateVal;
public:
    /**
     * @param root: the root of binary tree
     * @return: the root of the maximum average of subtree
     */
    TreeNode * findSubtree2(TreeNode * root) {
        // write your code here
        this->candidate = nullptr;
        this->candidateVal = -1;
        vector<int> res = getSubTree(root);
        return candidate;
    }

    vector<int> getSubTree(TreeNode* root)
    {
        vector<int> result;
        if(root==nullptr)
        {
            result.push_back(0);
            result.push_back(0);
            return result;
        }
        
        vector<int> leftpart = getSubTree(root->left);
        vector<int> rightpart = getSubTree(root->right);
        int totalSum = leftpart[0] + rightpart[0] + root->val;
        int totalNode = leftpart[1] + rightpart[1] + 1;
        double currentAvg = (double)(1.0f*totalSum/totalNode);
        result.push_back(totalSum);
        result.push_back(totalNode);
        if(candidate == nullptr)
        {
            candidate = root;
            this->candidateVal = currentAvg;
        }
        else
        {
             if(currentAvg > this->candidateVal)
             {
                 this->candidateVal = currentAvg;
                 this->candidate = root;
             }
        }
        return result;
    }
};