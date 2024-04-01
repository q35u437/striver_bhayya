TreeNode *previous = NULL;
void flatten(TreeNode* root) {
    if(!root){
        return;
    }
    flatten(root->right);
    flatten(root->left);
    root->right = previous;
    root->left = NULL;
    previous = root;
}
