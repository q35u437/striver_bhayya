vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root){
        return {};
    }
    vector<vector<int>> answer;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int length = q.size();
        vector<int> level;
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        answer.push_back(level);
    }
    return answer;
}
