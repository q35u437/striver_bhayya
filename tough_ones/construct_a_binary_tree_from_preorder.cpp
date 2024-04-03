TreeNode* getTree(vector<int> &A, int &counter, int upper_bound){
    if(counter >= A.size() or A[counter] > upper_bound){
        return NULL;
    }

    TreeNode *root = new TreeNode(A[counter++]);
    root->left = getTree(A, counter, root->val);
    root->right = getTree(A, counter, upper_bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int counter = 0;
    return getTree(preorder, counter, INT_MAX);
}
