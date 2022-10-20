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
    int height(TreeNode *root){
        if(root == NULL){
            return 0;
        }
        int l = height(root->left);
        int r = height(root->right);
        return max(l,r) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        bool diff = abs(height(root->left) - height(root->right))<=1;
        if(left && right && diff){
            return true;
        }
        else{
            return false;
        }
    }
};


// Linear time solution by calculating balance and height in 1 pass, simlar to diameter of btree soln
    pair<bool,int>getdia_and_height(TreeNode *root){
        if(root == NULL){
            return make_pair(true,0);
        }
        pair<bool,int> left = getdia_and_height(root->left);
        pair<bool,int> right = getdia_and_height (root->right);
        
        int d = abs(left.second - right.second);
        
        pair<bool,int> ans;
        
        ans.second = max(left.second , right.second)+1;
        if((d <=1) && (left.first == true && right.first == true)){
            ans.first = true;
        }else{
            ans.first = false;
        }
        return ans;
    }
    
    
    bool isBalanced(TreeNode* root) {
        return getdia_and_height(root).first;
    }