// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root){
        return "";
    }
    queue<TreeNode*> q;
    q.push(root);
    string answer = to_string(root->val)+" ";
    while(!q.empty()){
        int length = q.size();
        for(int i=0;i<length;i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                answer += to_string(node->left->val)+" ";
            }else{
                answer += "| ";
            }

            if(node->right){
                q.push(node->right);
                answer += to_string(node->right->val) + " ";
            }else{
                answer += "| ";
            }
        }
    }
    return answer;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data == "")
        return NULL;
    vector<string> values;
    string s;
    stringstream ss(data);
    getline(ss,s,' ');
    TreeNode *root = new TreeNode(stoi(s));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        getline(ss,s,' ');
        if(s=="|"){
            node->left = NULL;
        }else{
            node->left = new TreeNode(stoi(s));
            q.push(node->left);
        }
        getline(ss,s,' ');
        if(s=="|"){
            node->right = NULL;
        }else{
            node->right = new TreeNode(stoi(s));
            q.push(node->right);
        }
    }
    return root;
}
