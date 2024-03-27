vector<int> rightSideView(TreeNode* root) {
    if(!root){
        return {};
    }
    vector<int> answer;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
            if(i==length-1){
                answer.push_back(node->val);
            }
        }
    }
    return answer;
}
