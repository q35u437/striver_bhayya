    void preorder(TreeNode *root, vector<int> &answer){
        if(root){
            answer.push_back(root->val);
            if(root->left){
                preorder(root->left, answer);
            }
            if(root->right){
                preorder(root->right, answer);
            }
        }
    }
