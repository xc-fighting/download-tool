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
   vector<int> getNodes(TreeNode* root,int distance)
   {
       vector<int> result;
       if(root==nullptr)
       {
           return result;
       }
       int step = 0;
       queue<TreeNode*> nodequeue;
       nodequeue.push(root);
       bool find = false;
       while(nodequeue.empty()==false)
       {
           int size = nodequeue.size();
           if(step==distance)
           {
               find = true;
           }
           vector<int> tempbuffer;
           for(int i=0;i<size;i++)
           {
              TreeNode* frontNode = nodequeue.front();
              nodequeue.pop();
              tempbuffer.push_back(frontNode->val);
              if(frontNode->left != nullptr)
              {
                  nodequeue.push(frontNode->left);
              }
              if(frontNode->right != nullptr)
              {
                  nodequeue.push(frontNode->right);
              }
           }
           if(find)
           {
               result = vector<int>(tempbuffer);
               break;
           }
           step++;
       }
       return result;
   }
   vector<pair<TreeNode*,int>> nodes;
public:
    /**
     * @param root: the root of the tree
     * @param target: the target
     * @param K: the given K
     * @return: All Nodes Distance K in Binary Tree
     */
    vector<int> distanceK(TreeNode * root, TreeNode * target, int K) {
        // Write your code here
        vector<int> result;
        vector<int> below = getNodes(target,K);
        for(int elem:below)
        {
            result.push_back(elem);
        }

        //0 for left 1 for right
        vector<pair<TreeNode*,int>> tempbuffer;
        traverse(root,target,tempbuffer);
        int step = 1;
        for(int i=nodes.size()-1;i>=0;i--)
        {
            int distance = K - step;
          //  cout<<"distance:"<<distance<<endl;
            pair<TreeNode*,int> top = nodes[i];
            if(distance>0)
            {
                
                if(top.second == 0)
                {
                    vector<int> res = getNodes(top.first->right,distance-1);
                    for(int elem:res)
                    {
                        result.push_back(elem);
                    }
                }
                else
                {
                    vector<int> res = getNodes(top.first->left,distance-1);
                    for(int elem:res)
                    {
                        result.push_back(elem);
                    }
                }
            }
            else if(distance == 0)
            {
                result.push_back(top.first->val);
                break;
            }
            step++;
        }
        return result;

    }

    void traverse(TreeNode* root,TreeNode* target, vector<pair<TreeNode*,int>>& nodestack)
    {
       if(root==nullptr)
       {
           return;
       }
       
       if(root == target)
       {
           
           nodes = vector<pair<TreeNode*,int>>(nodestack);
           return;
       }

       nodestack.push_back(pair<TreeNode*,int>(root,0));
       traverse(root->left,target,nodestack);
       nodestack.pop_back();

       nodestack.push_back(pair<TreeNode*,int>(root,1));
       traverse(root->right,target,nodestack);
       nodestack.pop_back();

    }
};