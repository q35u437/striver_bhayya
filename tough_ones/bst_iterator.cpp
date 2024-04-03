stack<TreeNode *> s;
BSTIterator(TreeNode* root) {
    while(root){
        s.push(root);
        root = root->left;
    }
}

int next() {
    TreeNode *node = s.top();
    s.pop();
    TreeNode *check = node->right;
    while(check){
        s.push(check);
        check = check->left;
    }
    return node->val;   
}

bool hasNext() {
    return !s.empty();
}
