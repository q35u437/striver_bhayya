TreeNode* insertIntoBST(TreeNode* node, int val) {
    if(not node){
        return new TreeNode(val);
    }
    TreeNode *root = node;
    while(root){
        if(root->val < val){
            if(root->right){
                root = root->right;
            }else{
                root->right = new TreeNode(val);
                break;
            }
        }else{
            if(root->left){
                root = root->left;
            }else{
                root->left = new TreeNode(val);
                break;
            }
        }
    }
    return node;
}
