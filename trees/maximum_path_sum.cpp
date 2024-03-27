int maxi = INT_MIN;
int getMaxPathSum(TreeNode* node){
    if(!node){
        return 0;
    }
     int leftsum = max(0, getMaxPathSum(node->left));
    int rightsum = max(0,getMaxPathSum(node->right));
    maxi = max(maxi, leftsum+rightsum+node->val);
    return max(leftsum, rightsum) + node->val;
}
int maxPathSum(TreeNode* root) {
    getMaxPathSum(root);
    return maxi;
}
