bool checkBoth(TreeNode *node1, TreeNode *node2){
    if(!node1 and node2){
        return false;
    }

    if(node1 and !node2){
        return false;
    }

    if(!node1 and !node2){
        return true;
    }

    if(node1->val != node2->val){
        return false;
    }else{
        return true and checkBoth(node1->left, node2->left) and checkBoth(node1->right, node2->right);
    }
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    return checkBoth(p, q);
}
