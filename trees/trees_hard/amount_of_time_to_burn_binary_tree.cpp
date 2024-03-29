//leetcode id is : 2385
// in gfg it can be directly found
TreeNode* getAllParents(TreeNode *root, map<TreeNode*,TreeNode*> &parents, int start){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* startingpoint = NULL;
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->val == start)
                startingpoint = node;
            if(node->left){
                q.push(node->left);
                parents[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }
    return startingpoint;
}
int amountOfTime(TreeNode* root, int start) {
    map<TreeNode*,TreeNode*> parents;
    TreeNode* startingpoint = getAllParents(root, parents, start);
    int minutes = 0;
    set<TreeNode*> visited;
    queue<TreeNode*> q;
    q.push(startingpoint);
    visited.insert(startingpoint);
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                if(visited.count(node->left)==0){
                    q.push(node->left);
                    visited.insert(node->left);
                }
            }

            if(node->right){
                if(visited.count(node->right)==0){
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
        if(q.empty())
            break;
        minutes++;
    }
    return minutes;
}
