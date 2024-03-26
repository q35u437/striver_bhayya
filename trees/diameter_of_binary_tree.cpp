int maxh = INT_MIN;
int getDiameter(TreeNode *root){
    if(!root){
        return 0;
    }
    int lefth = getDiameter(root->left);
    int righth = getDiameter(root->right);
    maxh = max(maxh, lefth+righth);
    return max(lefth, righth) + 1;
}
int diameterOfBinaryTree(TreeNode* root){
    getDiameter(root);
    return maxh;
}
