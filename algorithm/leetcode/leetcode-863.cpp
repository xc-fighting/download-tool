/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findNodes(vector<int>& result,TreeNode* root, int k, int curDepth) {
        if( root == nullptr ) {
            return;
        }
     //   cout<<k<<" "<<curDepth<<endl;
        if( curDepth == k ) {
            result.push_back(root->val);
            return;
        }
        findNodes(result,root->left,k,curDepth+1);
        findNodes(result,root->right,k,curDepth+1);
    }
    
    int getDistanceToTarget(vector<int>& result,TreeNode* root, TreeNode* target,int k) {
        if( root == nullptr ) {
            return -1;
        }
        if( root == target ) {
            vector<int> tempbuffer;
            findNodes(tempbuffer,root,k,0);
            for(int elem: tempbuffer) { 
                result.push_back(elem);
            }
            return 0;
        }
      //  cout<<"current node:"<<root->val<<endl;
        int leftDistance = getDistanceToTarget(result, root->left, target, k);
        if( leftDistance != -1 ) {
         //   cout<<"left distance:"<<leftDistance<<endl;
            int distanceToRoot = leftDistance + 1;
            if( distanceToRoot == k ) {
                 result.push_back(root->val);
            }
            else {
                 int distanceLeft = k - distanceToRoot;
                 // cout<<"distance left:"<<distanceLeft<<endl;
                 vector<int> tempbuffer;
                 findNodes(tempbuffer,root->right,distanceLeft-1,0);
                 for(int value: tempbuffer) {
                      result.push_back(value);
                 }
            }
            
            return distanceToRoot;
        }
        
        int rightDistance = getDistanceToTarget(result, root->right, target, k);
        if( rightDistance != -1 ) {
            int distanceToRoot = rightDistance + 1;
            if( distanceToRoot == k ) {
                result.push_back(root->val);
            }
            else {
                 int distanceLeft = k - distanceToRoot;
                 vector<int> tempbuffer;
                 findNodes(tempbuffer,root->left,distanceLeft-1,0);
                 for(int value: tempbuffer) {
                     result.push_back(value);
                 }
            }
            
            return distanceToRoot;
        }
        
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        getDistanceToTarget(result,root,target,k);
        return result;
        
    }
};
