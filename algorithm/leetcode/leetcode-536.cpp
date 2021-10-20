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
    TreeNode* str2tree(string s) {
        if( s.size() == 0 ) {
            return nullptr;
        }
        int index = 0;
        int number = 0;
        int flag = 1;
        if( s[0] == '-' ) {
            flag = -1;
            index++;
        }
        while( index < s.size() && s[index] >= '0' && s[index] <= '9' ) {
            number = number * 10 + s[index] - '0';
            index++;
        }
        number = number * flag;
        TreeNode* root = new TreeNode(number);
        if( index == s.size() ) {
            
            return root;
        }
        
        int match = 1;
        index++;
        int start = index;
        
        while( index < s.size()  ) {
            if( s[index] == '(' ) {
                match++;
            }
            if( s[index] == ')' ) {
                match--;
            }
            if(match==0){
                break;
            }
            index++;
        }
        
        int len = index - start;
        string leftstr = s.substr(start, len);
        
        root->left = str2tree(leftstr);
        
        
        index++;
        if(index == s.size()) {
            return root;
        }
        match = 1;
        index++;
        start = index;
        while( index < s.size() ) {
            cout<<s[index]<<endl;
            if( s[index] == '(' ) {
                match++;
            }
            if( s[index] == ')' ) {
                match--;
            }
            if( match == 0 ) {
               
                break;
            }
            index++;
        }
        len = index - start;
        string rightstr = s.substr(start, len);
        
        root->right = str2tree(rightstr);
        return root;
    }
};