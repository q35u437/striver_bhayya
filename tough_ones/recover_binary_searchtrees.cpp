TreeNode *first, *last, *previous;
void changeTree(TreeNode *root){
    if(!root){
        return;
    }
    changeTree(root->left);
    if(previous != NULL and previous->val > root->val ){
        if(first == NULL){
            first = previous;
            last = root;
        }else{
            last = root;
        }
    }
    previous = root;
    changeTree(root->right);
}
void recoverTree(TreeNode* root) {
    changeTree(root);
    swap(first->val, last->val);
    return;
}
