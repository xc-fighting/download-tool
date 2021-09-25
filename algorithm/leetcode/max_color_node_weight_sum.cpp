#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int value) {
		this->val = value;
		this->left = nullptr;
		this->right = nullptr;
	}
};

/*
  
  param: 
    root: root of binary tree
    color: -1 means unknown, 0 means not color current node, 1 means color it
  return:
     the max weight
*/
int getMaxWeightRecursive( TreeNode* root, int color ) {
    if( root == nullptr ) {
    	 return 0;
    }
    
    int currentWeight = root->val;
    if( color == 0 ) {
    	
    	int colorLeft = getMaxWeightRecursive( root->left, 1 );
    	int colorRight = getMaxWeightRecursive( root->right, 1 );
    	int notColorLeft = getMaxWeightRecursive(root->left, 0);
    	int notColorRight = getMaxWeightRecursive(root->right, 0);
    	
    	int candidate1 = colorLeft + colorRight;
    	int candidate2 = colorLeft + notColorRight;
    	int candidate3 = notColorLeft + colorRight;
    	int candidate4 = notColorLeft + notColorRight;
    	vector<int> buffer{candidate1,candidate2,candidate3,candidate4};
    	sort(buffer.begin(),buffer.end());
    	return buffer[3];


    }
    else {
       
       int notColorLeft = getMaxWeightRecursive(root->left, 0);
       int notColorRight = getMaxWeightRecursive(root->right, 0);
       return currentWeight + notColorLeft + notColorRight;

    }
}

int getMaxWeight( TreeNode* root ) {
	if( root == nullptr ) {
		return 0;
	} 
    
    int candidate1 = getMaxWeightRecursive(root,0);
    int candidate2 = getMaxWeightRecursive(root,1);
    return max(candidate1,candidate2);
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    cout<<getMaxWeight(root)<<endl;
}