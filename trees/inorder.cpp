    void inorder(TreeNode *root, vector<int> &answer){
        if(root){
            if(root->left){
                inorder(root->left, answer);
            }
            answer.push_back(root->val);
            if(root->right){
                inorder(root->right, answer);
            }
        }
    }
