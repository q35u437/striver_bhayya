int maxDepth(TreeNode* root) {
    if(!root){
        return 0;
    }
    int depth = 0;
    queue<TreeNode *>q;
    q.push(root);
    while(!q.empty()){
        int length = q.size();
        depth++;
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return depth;
}
