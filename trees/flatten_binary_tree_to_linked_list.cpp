void flatten(TreeNode* root) {
    //morris traversal
    TreeNode *current = root;
    while(current){
        if(!current->left){
            current->left = NULL;
            current = current->right;
        }else{
            TreeNode *previous = current->left;
            while(previous->right){
                previous = previous->right;
            }
            previous->right = current->right;
            current->right = current->left;
            current->left = NULL;
        }
    }   
}
