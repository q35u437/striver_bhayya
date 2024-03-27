vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if(!root){
        return {};
    }
    vector<vector<int>> answer;
    queue<TreeNode*> q;
    q.push(root);
    int number = 1;
    while(!q.empty()){
        int length = q.size();
        vector<int> level;
        for(int i=0;i<length;i+=1){
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
        if(number%2){
            answer.push_back(level);
        }else{
            reverse(level.begin(), level.end());
            answer.push_back(level);
        }
        number++;
    }
    return answer;
}
