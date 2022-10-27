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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,vector<int>>> hmap;
        queue<pair<TreeNode *,pair<int,int>>> q;
        vector<vector<int>> res;
//     empty tree
        if(root == NULL){
            return res;
        }
        
//         add root node to queue
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<TreeNode*,pair<int,int>> front = q.front();
            q.pop();
//            create data for map
            TreeNode *frontNode = front.first;
            int hdist = front.second.first;
            int level = front.second.second;
            
            hmap[hdist][level].push_back(frontNode->val);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hdist-1,level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hdist+1,level+1)));
            }
    }
               
        for(auto i : hmap){
            vector<int> tmp;
            for(auto j: i.second){
            
                for(auto k: j.second){
                tmp.push_back(k);    
                }
                
                
            }
            res.push_back(tmp);
        }
return res;
               }
};