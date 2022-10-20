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
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right) + 1;
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
       if(root == NULL){
           return 0;
       } 
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int b = height(root->left) + height(root->right) ;
        return max(b,max(l,r)) ;
    }

    pair<int,int> calculatediameter(TreeNode *root){
        // TC - O(n) ; we calculate diameter and height of btree together in 1 pass
        if(root == NULL){
            return make_pair(0,0);
        }
//         first contains diameter, second contains height
        pair<int,int> p1 = calculatediameter(root->left);
        pair<int,int> p2 = calculatediameter(root->right);
        int op1 = p1.first;
        int op2 = p2.first;
        int op3 = p1.second + p2.second;
        pair<int,int> ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(p1.second, p2.second)+1 ;
        return ans;
    }
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        return calculatediameter(root).first;
    }
};