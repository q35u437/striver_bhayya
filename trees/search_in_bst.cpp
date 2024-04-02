TreeNode* getNode(TreeNode *root, int value){
    if(!root){
        return NULL;
    }

    if(root->val == value){
        return root;
    }

    if(root->val < value){
        if(root->right)
           return getNode(root->right, value);
        else
            return NULL;
    }else{
        if(root->left)
            return getNode(root->left, value);
        else
            return NULL;
    }
}
TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode *answer = getNode(root, val);
    return answer;
}
