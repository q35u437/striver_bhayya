//the naive approach of this algorithm will result in O(n^2).
//whereas if we use the same maximum height code and tweek it a bit we can check for balancing property
//a binary tree is said to be balanced if height between leftsubtree and rightsubtree is -1 or 0 or +1.
int check(TreeNode *root){
    if(!root){
        return 0;
    }
    int lefth = check(root->left);
    int righth = check(root->right);
    if(lefth == -1 or righth == -1){
        return -1;
    }
    if(abs(lefth-righth) > 1){
        return -1;
    }
    return max(lefth, righth) + 1;
}
bool isBalanced(TreeNode* root) {
    return check(root)!=-1;
}
