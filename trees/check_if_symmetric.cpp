bool checkSymmetric(TreeNode *node1, TreeNode *node2){
    if(node1 and !node2){
        return false;
    }

    if(!node1 and node2){
        return false;
    }

    if(!node1 and !node2){
        return true;
    }

    if(node1->val  != node2->val){
        return false;
    }
    return true and checkSymmetric(node1->left,node2->right) and checkSymmetric(node1->right,node2->left);
}
bool isSymmetric(TreeNode* root) {
    return checkSymmetric(root,root);
}
