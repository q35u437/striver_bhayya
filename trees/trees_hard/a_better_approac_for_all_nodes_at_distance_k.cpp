void getAllParents(TreeNode *root, map<TreeNode*, TreeNode*> &parents){
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                parents[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                parents[node->right] = node;
                q.push(node->right);
            }
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    map<TreeNode*, TreeNode*> parents;
    getAllParents(root, parents);
    queue<TreeNode*> q;
    q.push(target);
    set<TreeNode*> visited;
    visited.insert(target);
    while(!q.empty() and k--){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                if(visited.count(node->left) == 0){
                    q.push(node->left);
                    visited.insert(node->left);
                }
            }

            if(node->right){
                if(visited.count(node->right) == 0){
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }

            if(parents[node]){
                if(visited.count(parents[node]) == 0){
                    q.push(parents[node]);
                    visited.insert(parents[node]);
                }
            }
        }
    }
    vector<int> answer;
    while(!q.empty()){
        TreeNode *node = q.front();
        answer.push_back(node->val);
        q.pop();
    }
    return answer;
}
