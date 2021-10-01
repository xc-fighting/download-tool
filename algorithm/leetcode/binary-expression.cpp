/*

Binary Expression Tree

AND
/  \
OR  False
/  \
True False

step 1:first evaluate the result
step 2:min flips to change the result

*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
public:
	string value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(string v) {
		this->value = v;
		this->left = nullptr;
		this->right = nullptr;
	}

};


bool evaluate(TreeNode* root) {

	if(root == nullptr) {
		return true;
	}

	if( root->left == nullptr && root->right == nullptr ) {
		//leaf node, return the bool value
		string boolStr = root->value;
		if( boolStr.compare("True") == 0 ) {
			return true;
		}
		return false;
	}

	// for op node
	string opStr = root->value;

	bool leftPart = evaluate(root->left);
	bool rightPart = evaluate(root->right);

	if( opStr.compare("OR") ) {
		return leftPart || rightPart;
	}

	return leftPart && rightPart;
}



//return a size 3 vector
//result[3]
//result[0] is the original result 0 for false, 1 for true
//result[1] is the minFlip to make it true
//result[2] is the minFlip to make it false
vector<int> getMinFlipRecursive(TreeNode* root) {

    if( root->left == nullptr && root->right == nullptr ) {
         string valueStr = root->value;
         vector<int> result(3,-1);
         if( valueStr.compare("True") == 0 ) {
              result[0] = 1;//original is true
              result[1] = 0;
              result[2] = 1; //flip to False
         }
         else {
         	 result[0] = 0;//original is false
         	 result[1] = 1;
         	 result[2] = 0;
         }
         return result;

    }

    vector<int> ret(3,-1);
    string opStr = root->value;
    cout<<opStr<<endl;

    vector<int> leftpart = getMinFlipRecursive(root->left);
    vector<int> rightpart = getMinFlipRecursive(root->right);

    int originalLeft = leftpart[0];
    int originalRight = rightpart[0];
    int originalCur = -1;

    //operator is or
    if( opStr.compare("OR") == 0 ) {
        if( originalLeft == 1 || originalRight == 1 ) {
        	originalCur = 1;
        }
        else {
        	originalCur = 0;
        }
    }
    else {
    	 if(originalLeft == 0 || originalRight == 0) {
    	 	originalCur = 0;
    	 }
    	 else {
    	 	originalCur = 1;
    	 }
    }

    ret[0] = originalCur;
    if( ret[0] == 0 ) {
    	//directly assign
    	ret[2] = 0;
        //check ret[1]
        // want to chage from false to true
        // check op
        if(opStr.compare("OR") == 0 ) {
            // or operation
            //left and right original both 0
            ret[1] = min(leftpart[1],rightpart[1]);
        }
        else {
            // and operator
            // false value
            if( originalLeft == 0 && originalRight == 0 ) {
            	ret[1] = leftpart[1] + rightpart[1];
            }

            if( originalLeft == 1 && originalRight == 0 ) {
            	ret[1] = rightpart[1];
            }

            if( originalLeft == 0 && originalRight == 1 ) {
            	ret[1] = leftpart[1];
            }
        }

    }
    else {
        //directly assign
    	ret[1] = 0;
    	//original is true
    	if(opStr.compare("AND") == 0 ) {
    		ret[2] = min(leftpart[2],rightpart[2]);
    	}
    	else {
    		//or operator
    		if( originalLeft == 1 && originalRight == 1 ) {
    			ret[2] = leftpart[2] + rightpart[2];
    		} 

    		if( originalLeft == 1 && originalRight == 0 ) {
    			ret[2] = leftpart[2];
    		}

    		if( originalLeft == 0 && originalRight == 1 ) {
    			ret[2] = rightpart[2];
    		}
    	}
    }

    return ret;


}

int getMinFlip(TreeNode* root) {
    vector<int> result = getMinFlipRecursive(root);
    if( result[0] == 1 ) {
    	return result[2];
    }
    else {
    	return result[1];
    }
}

int main() {

    TreeNode* root = new TreeNode("AND");
    root->right = new TreeNode("False");
    root->left = new TreeNode("AND");
    root->left->left = new TreeNode("True");
    root->left->right = new TreeNode("False");
    bool result = evaluate(root);
    if( result ) {
    	cout<<"True"<<endl;
    }
    else {
    	cout<<"False"<<endl;
    }
    cout<<getMinFlip(root)<<endl;
	return 0;
}