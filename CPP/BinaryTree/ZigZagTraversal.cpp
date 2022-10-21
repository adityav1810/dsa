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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root== NULL){
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        bool lToR = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            
            for(int i = 0; i<size;i++){
                
                TreeNode *front = q.front();
                q.pop();
                
                int idx = lToR ? i : size - i- 1;
                temp[idx] = front->val;
                
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
                
               
             
            }
             lToR = !lToR;
             res.push_back(temp);  
        }
        
        
        
        
        return res;
    }
};