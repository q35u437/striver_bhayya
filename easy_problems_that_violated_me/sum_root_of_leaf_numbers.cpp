int getAnswer(TreeNode* root, int sum){
    if(not root){
        return 0;
    }
    sum = sum*10 + root->val;
    if(not root->left and not root->right)
        return sum;
    return getAnswer(root->left, sum) + getAnswer(root->right, sum);
}
int sumNumbers(TreeNode* root) {
    return getAnswer(root, 0); 
}
