TreeNode* getAnswer(TreeNode *root, TreeNode *p, TreeNode *q){
    if(!root){
        return NULL;
    }

    if(root == p){
        return root;
    }

    if(root == q){
        return root;
    }
    TreeNode* left = getAnswer(root->left, p, q);
    TreeNode* right = getAnswer(root->right, p, q);
    if(left == NULL and right != NULL){
        return right;
    }

    if(left != NULL and right == NULL){
        return left;
    }

    if(left == NULL and right == NULL){
        return NULL;
    }

    return root;

}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return getAnswer(root, p, q);
}
