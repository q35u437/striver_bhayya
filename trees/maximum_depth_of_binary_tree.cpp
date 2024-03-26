int getMax(TreeNode *node){
    if(!node){
        return 0;
    }else{
        return max(getMax(node->left), getMax(node->right)) + 1;
    }
}
int maxDepth(TreeNode* root) {
    return getMax(root);
}
