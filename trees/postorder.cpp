    void postorder(TreeNode* root, vector<int> &answer){
        if(root){
            if(root->left){
                postorder(root->left, answer);
            }
            if(root->right){
                postorder(root->right, answer);
            }
            answer.push_back(root->val);
        }
    }
