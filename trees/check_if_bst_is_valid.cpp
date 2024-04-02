bool check(TreeNode *root, long long left, long long right){
    if(!root){
        return true;
    }
    return check(root->left,left,root->val) and (root->val > left and root->val < right) and check(root->right,root->val,right);
}
bool isValidBST(TreeNode* root) {
    if(!root){
        return true;
    }
    return check(root, LLONG_MIN, LLONG_MAX);
}
