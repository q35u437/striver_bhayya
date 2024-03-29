// the flow is basically we are forming the graph first and then by doing BFS we are finding all the nodes at a distance K 
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    //forming the graph
    map<int, vector<int>> graph;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                if(graph.count(node->left->val) == 0)
                    graph[node->left->val] = {};
                if(graph.count(node->val) == 0)
                    graph[node->val] = {};
                graph[node->left->val].push_back(node->val);
                graph[node->val].push_back(node->left->val);
                q.push(node->left);
            }
            if(node->right){
                if(graph.count(node->right->val) == 0)
                    graph[node->right->val] = {};
                if(graph.count(node->val) == 0)
                    graph[node->val] = {};
                graph[node->right->val].push_back(node->val);
                graph[node->val].push_back(node->right->val);
                q.push(node->right);
            }
        }
    }
    //now do BFS
    //node and distance
    queue<pair<int, int>> kyu;
    set<int> visited;
    visited.insert(target->val);
    vector<int> answer;
    kyu.push({target->val, 0});
    while(!kyu.empty()){
        auto it = kyu.front();
        kyu.pop();
        int node = it.first;
        if(it.second == k)
            answer.push_back(node);
        for(int neighbour : graph[node]){
            if(visited.count(neighbour) == 0){
                kyu.push({neighbour, it.second+1});
                visited.insert(neighbour);
            }
        }
    }
    return answer;
}
