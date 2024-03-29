//get the total number of nodes in a binary tree in O(log^2) time complexity
//here the getLeftHeight and getRightHeight will take O(logn) time and the getTotalCount is not called for all nodes but only log(n) nodes.
//So total time complexity is O(logn^2).
int getLeftHeight(TreeNode *node){
    int height = 1;
    while(node){
        height++;
        node = node->left;
    }
    return height;
}
int getRightHeight(TreeNode *node){
    int height = 1;
    while(node){
        height++;
        node = node->right;
    }
    return height;
}
int getTotalCount(TreeNode* node){
    if(!node){
        return 0;
    }
    int leftheight = getLeftHeight(node->left);
    int rightheight = getRightHeight(node->right);
    if(leftheight == rightheight) return (1<<leftheight) - 1;
    return 1 + getTotalCount(node->left) + getTotalCount(node->right);
}
int countNodes(TreeNode* root) {
    return getTotalCount(root);
}
