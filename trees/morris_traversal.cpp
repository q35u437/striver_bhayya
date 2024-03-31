vector<int> inorderTraversal(TreeNode* root) {
    //morris traversal
    //threaded binary tree FTW
    vector<int> inorder;
    TreeNode *current = root;
    while(current){
        if(current->left){
            TreeNode *alt = current->left;
            while(alt->right and alt->right != current){
                alt = alt->right;
            }
            if(alt->right){
                alt->right = NULL;
                inorder.push_back(current->val);
                current = current->right;
            }else{
                alt->right = current;
                current = current->left;
            }
        }else{
            inorder.push_back(current->val);
            current = current->right;
        }
    }
    return inorder;
}
