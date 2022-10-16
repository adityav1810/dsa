 int getHeight(TreeNode *root){
    // Recursion based method
        if(root == NULL){
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int h = max(left,right);
        return h+1;
    }
    

     int getHeight(TreeNode *root){
        // Height of tree using recursion
        queue<TreeNode*> q;
        if(root == NULL){
            return 0;
        }
        int height = 0;
        q.push(root);
        while(!q.empty()){
            
            int size = q.size();
            for(int i = 0;i<size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left !=NULL){
                    q.push(temp->left);
                }
                if(temp->right !=NULL){
                    q.push(temp->right);
                }
            }
            height ++;
        }
        return height;
        
    }
    


